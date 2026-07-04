# Simple Spring Mass Simulation

A lightweight, 2D spring-mass harmonic oscillation simulation built in C++ using the **SDL3** library. This project demonstrates simple harmonic motion, visualizing both the spring component and the oscillating mass.

## Features

* **Real-time Physics Visuals:** Simulates a block hanging from a fixed hook, oscillating under a modified sinusoidal wave function.
* **Dynamic Spring Rendering:** The spring automatically stretches and contracts dynamically based on the block's real-time position.
* **Built with SDL3:** Benchmarked using the latest major iteration of the Simple DirectMedia Layer library.

---

## The Physics Behind It

The simulation models a mass attached to an elastic cord pivoted at a fixed point. Unlike a standard spring, an elastic band only exerts a restoring force when stretched beyond its natural resting length.

The vertical displacement is Defined as:

$$y(t) = {A}\cdot \sin\left({\omega \cdot t}\right)$$

Where:
* $A$ is the initial amplitude of the stretch.
* $\omega$ is the angular frequency representing the elasticity.
* $t$ is the elapsed time step.

---
