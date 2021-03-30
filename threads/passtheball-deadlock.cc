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
  if (!target->has_ball) {
    target->has_ball = true;
    this->has_ball = false;
    printf("... P%u caught!\n", target->id);
  } else {
    printf("... P%u already has a ball!\n", target->id);
  }
  target->m.unlock();
}

void player_threadfunc(Player* me) {
  printf("P%u joins the game!\n", me->id);
  while (true) {
    me->m.lock();
    Player* to;
    if (rand() % 2 == 1) {
      to = me->next;
    } else {
      to = me->prev;
    }
    me->pass(to);
    me->m.unlock();
  }
}

int main() {
  Player p[NUM_PLAYERS];
  std::thread* pth[NUM_PLAYERS];

  for (unsigned int i = 0; i < NUM_PLAYERS; i++) {
    if (i == 0 || i == 2) {
      p[i].has_ball = true;
    }
    p[i].id = i;
    p[i].next = &p[(i + 1) % NUM_PLAYERS];
    p[i].prev = &p[(i + NUM_PLAYERS - 1) % NUM_PLAYERS];
  }

  for (int i = 0; i < NUM_PLAYERS; i++) {
    pth[i] = new std::thread(player_threadfunc, &p[i]);
  }

  for (int i = 0; i < NUM_PLAYERS; i++) {
    pth[i]->join();
    delete pth[i];
  }
}
