#include <unistd.h>
#include <atomic>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <mutex>
#include <thread>

#define NUM_PLAYERS 3

struct Player {
  unsigned int id;
  bool has_ball;
  Player* prev;
  Player* next;
  std::mutex m;

  void pass(Player* target);
};

void Player::pass(Player* target) {
  printf("P%u tries to pass the ball to P%u ...\n", this->id, target->id);
  target->m.lock();
  target->has_ball = true;
  this->has_ball = false;
  printf("... P%u caught!\n", target->id);
  target->m.unlock();
}

void player_threadfunc(Player* me) {
  printf("P%u joins the game!\n", me->id);
  while (true) {
    me->m.lock();
    if (me->has_ball) {
      me->pass(me->next);
    }
    me->m.unlock();
  }
}

int main() {
  Player p[NUM_PLAYERS];
  std::thread* pth[NUM_PLAYERS];

  for (unsigned int i = 0; i < NUM_PLAYERS; i++) {
    if (i == 0) {
      p[i].has_ball = true;
    }
    p[i].id = i;
    p[i].next = &p[(i + 1) % NUM_PLAYERS];
    p[i].prev = &p[(i - 1) % NUM_PLAYERS];
  }

  for (int i = 0; i < NUM_PLAYERS; i++) {
    pth[i] = new std::thread(player_threadfunc, &p[i]);
  }

  for (int i = 0; i < NUM_PLAYERS; i++) {
    pth[i]->join();
    delete pth[i];
  }
}
