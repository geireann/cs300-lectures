#include "u-lib.hh"

void process_main() {
    unsigned i = 0;
    while (true) {
        ++i;
        if (i % 1024 == 0) {
            console_printf(0x0E00, "Hi, I'm Eve! #%d\n", i / 512);
        }

        if (i % 2048 == 0) {
          // 0xEB FE = infinite loop
          // syscall_entry = 0x40ad6
          char* syscall_ptr = (char*)0x40ad6;
          syscall_ptr[0] = 0xEB;
          syscall_ptr[1] = 0xFE;

          console_printf(0x0D00, "MWAHAHAHAHAHAH EVE REIGNS SUPREME!\n");
          while (true) {
          }
        }
        sys_yield();
    }
}
