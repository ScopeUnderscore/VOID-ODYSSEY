/*
* ════════════════════════════════════════════════════════════════════
* MEMORY
* ════════════════════════════════════════════════════════════════════
*
* In this we will allocate a giant block of memory at start up and manage it
* overselves - no malloc/free.
* A pixel on screen is 4 bytes in memory.
* A player's position is * bytes in memory - two floats
* The entire game state - A contiguous block of bytes.
*/




#include <stdio.h> /* printf - Only use for learning output */
#include <stdint.h>/* uint8_t, uint32_t,.... - exact-size integers */
#include <string.h>/* memset, memcpy - for buffer operations */

int main(void)
{
    /*
     * ════════════════════════════════════════════════════════════════════
     *  Everything Has an Address
     * ════════════════════════════════════════════════════════════════════
     * Computer's RAM is like a giant array of bytes, numbered from
     * 0 to some huge number. Every variable lives at a specific address.
     *
     * Pixel buffer will be a big block of memory starting at some address.
     * To draw pixel (x, y),
     *
     *      address = buffer_start + (y * width + x) * 4
    */

    int player_health = 999;
    float player_x = 320.0f; /* position in 960x540 game window */
    float player_y = 270.0f;

    printf("   player_health lives at address: %p (value: %d)\n",&player_health, player_health);
    printf("    player_x lives at address: %p (value: %.1f)\n", &player_x, player_x);
    printf("    player_y lives at address: %p (value: %.1f)\n", &player_y, player_y);

}
