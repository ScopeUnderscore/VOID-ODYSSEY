# Void Odyssey: Learning C from Scratch

**Void Odyssey** is a long-term learning project designed to teach C, memory management, and low-level system architecture by building a 2D space shooter engine entirely from scratch.

There are no external game libraries (like SDL or OpenGL) used here. Everything from opening a window, plotting pixels, handling input, to allocating memory is written by hand. This project heavily follows the architecture philosophy of [Handmade Hero](https://handmadehero.org/).

## 🎯 The Purpose

The goal of this repository isn't just to make a game—it’s to understand what happens under the hood when software runs.

By building this, the goal is to master:
*   **Memory Management:** Moving away from standard `malloc`/`free` and understanding pointer arithmetic, memory layout, and custom Arena allocators.
*   **Platform Independence:** Architecting the code by strictly separating the OS-specific layer (macOS/Objective-C) from the pure game logic (Platform-agnostic C).
*   **Data-Oriented Design:** Structuring data for the CPU cache rather than following traditional object-oriented patterns.
*   **Software Rendering:** Drawing pixels directly to a memory buffer using math and bitwise operations instead of a GPU.

## 🗺️ Project Roadmap

The project is broken down into progressive phases. Every phase introduces new concepts that immediately map to tangible, visual outcomes.

*   **Phase 0: C Foundations**
    *   *Focus:* Memory addresses, pointer arithmetic, struct layouts, bitwise color packing, function pointers, and the preprocessor.
    *   *Status:* **Completed** (`phase_00_foundations/`)
*   **Phase 1: Opening a Window**
    *   *Focus:* macOS platform layer (`NSWindow`), creating the first offscreen pixel buffer.
*   **Phase 2: Software Renderer**
    *   *Focus:* Drawing primitives (pixels, rects, lines), color interpolation, and a parallax star field.
*   **Phase 3: Input & The Game Loop**
    *   *Focus:* Fixed-timestep loops, keyboard states, and putting a moving ship on the screen.
*   **Phase 4: Entities & Collision**
    *   *Focus:* Struct arrays, AABB collision, projectiles, and enemy spawning.
*   **Phase 5: Memory Arenas**
    *   *Focus:* Ripping out standard allocation and building custom linear allocators.
*   **Phase 6: Visual Polish & Particles**
    *   *Focus:* Pool allocators, alpha blending, explosions, and screen shake.
*   **Phase 7: Audio Synthesis**
    *   *Focus:* Ring buffers, Core Audio, and generating sound effects from math.
*   **Phase 8: Asset Loading & Hot Reloading**
    *   *Focus:* Binary parsing, `dlopen`, and live code editing without restarting the game.

## 🛠️ Environment Setup

*   **Compiler:** Clang (`cc`)
*   **OS:** macOS (Apple Silicon / ARM64)
*   **Dependencies:** Standard C Library, native macOS frameworks (Cocoa, CoreGraphics, CoreAudio).
