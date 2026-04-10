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

    /*
    * the addresses are close together! thats because these variables are on
    * the STACK -  a region of memory that grows/shrinks automatically as functions
    * are called/return.
    *
    * '&' - Address -of- Operator gives the address of any variable.
    * '%' -  Format string - tells what kind of variable follows.

    */
   /*
     * ════════════════════════════════════════════════════════════════════
     * Sizes Matter - sizeof
     * ════════════════════════════════════════════════════════════════════
     *
     * In the game engine, a pixel is $ bytes (ARGB). A position is 8 bytes
     * (two floats). Knowing sizes is essential for :
     *      - Allocating the right amount of memory
     *      - Calculating buffer offsets
     *      - Understanding cache performance
   */

    printf("=== Sizes Matter ===\n\n");
    printf("  sizeof(char)     = %zu bytes  (1 color channel)\n", sizeof(char));
    printf("  sizeof(int)      = %zu bytes\n", sizeof(int));
    printf("  sizeof(float)    = %zu bytes  (one coordinate)\n", sizeof(float));
    printf("  sizeof(double)   = %zu bytes\n", sizeof(double));
    printf("  sizeof(int *)    = %zu bytes  (a pointer — always this on 64-bit)\n\n", sizeof(int *));


    /* Exact-size types — these are what we'll use in the engine */
    printf("  --- Exact-size types (we'll use these in the engine) ---\n");
    printf("  sizeof(uint8_t)  = %zu byte   (one color channel: 0-255)\n", sizeof(uint8_t));
    printf("  sizeof(uint16_t) = %zu bytes  (audio sample)\n", sizeof(uint16_t));
    printf("  sizeof(uint32_t) = %zu bytes  (one ARGB pixel!)\n", sizeof(uint32_t));
    printf("  sizeof(uint64_t) = %zu bytes\n\n", sizeof(uint64_t));

    /*
     *  use uint8_t, uint32_t etc. instead of int/long
     *  because their sizes are GUARANTEED. 'int' might be 2 or 4 bytes
     *  depending on the platform. uint32_t is ALWAYS 4 bytes.
     *  In a game engine, this matters because our pixel format is exact.
     *
     *  size_ t - is unsigned, only positive integers.format string for this
     *  is 'zu':
     *      - z - length of modifier for size_t.
     *      - u -  stands for unsigned.
     */

     /*
     * ════════════════════════════════════════════════════════════════════
     *  The Stack — Automatic Memory
     * ════════════════════════════════════════════════════════════════════
     *
     * Variables declared in a function live on the STACK.
     * The stack is fast but limited (usually ~8MB).
     *
     * for the game engine: local variables, frame-temporary data.
     * NOT for the pixel buffer (960 * 540 * 4 = ~2MB per frame).
     *   - Use the Stack for: int score, float player_x, Matrix4 transformation.
     *   - Use the Heap for: Textures, Sounds, Pixel Buffers, Map Data.
     * Stack = Small, fast, and temporary.
     * Heap = Large, manual, and persistent.
     */

    printf("===Stack Memory ===\n\n");

    int array_on_stack[4] = {0xFF0000, 0x00FF00, 0x0000FF, 0xFFFFFF};
    /* This is like having 4 pixels on the stack: red, green, blue, white */

    printf("  4 'pixels' on the stack:\n");
    for (int i = 0; i < 4; i++){
        printf(" pixel[%d] at %p = 0x%06X\n",
                i, &array_on_stack[i], array_on_stack[i]);
    }

    /* addresses differ by exactly sizeof(int) = 4 bytes */
    printf("\n  Address difference between pixels: %ld bytes (should be %zu)\n\n",
           (long)((char *)&array_on_stack[1] - (char *)&array_on_stack[0]),
           sizeof(int));


}





