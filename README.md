# Advanced Line Following Robot with Obstacle Avoidance System on AVR ATmega128 V2

## 🧠 Introduction

This project is an advanced line-following robot system with integrated obstacle avoidance capabilities, based on the **AVR ATmega128** microcontroller. The robot operates entirely on simple logic-based algorithms instead of PID, making it suitable for educational purposes, research, and fundamental embedded system development.

---

## ⚙️ Specifications

- **Main Microcontroller**: ATmega128  
- **Number of Line Sensors**: 3 infrared sensors (Left, Center, Right)  
- **Obstacle Detection Sensor**: HC-SR04 (Ultrasonic)  
- **Motor Driver**: L298N  
- **Programming Language**: C (AVR-GCC)  
- **Power Supply**: 7.4V–12V battery or adapter

---

## 📦 Hardware Components

| Component               | Quantity | Description                     |
|------------------------|----------|---------------------------------|
| ATmega128              | 1        | Main microcontroller            |
| Infrared Sensors       | 3        | Line following (Left – Center – Right) |
| HC-SR04 Ultrasonic     | 1        | Obstacle detection              |
| L298N Motor Driver     | 1        | Drives two DC motors            |
| DC Motors              | 2        | Connected to wheels             |
| Wheels                 | 2        | Mounted on DC motors            |
| Power Supply (7.4V–12V)| 1        | Li-ion battery or adapter       |

---

## 🧭 Working Principle

### 1. **Line Following Using 3 Infrared Sensors**
- The center sensor detects the black line when the sensor reading is `010`.
- If the sensor pattern (Left–Center–Right) is `110` or `100`, the robot turns **left**.
- If the pattern is `011` or `001`, the robot turns **right**.
- If the pattern is `111`, the robot defaults to turning **left**.

### 2. **Obstacle Avoidance Using Ultrasonic Sensor**
- Distance is measured using the HC-SR04 ultrasonic sensor.
- If an obstacle is detected within **15cm**, the robot stops, turns left, records the distance, then turns right and records the other distance.
- It compares both values:  
   - If **Left distance ≥ Right distance**, the robot turns **left**.  
   - Otherwise, it turns **right**.
- Once the robot selects a direction, it moves forward a short distance, then adjusts direction again until the line is detected.
- No PID control is used — decisions are made based on fixed thresholds and simple logic.
- In the future, I plan to improve this model by using **5 line sensors** and implementing PID-based obstacle avoidance.

---

## 💡 Highlights

- **No PID algorithm** — simple and easy to understand, ideal for beginners.
- **Clear separation of functionalities** — line following and obstacle avoidance operate independently but in coordination.
- **Direct motor control** using L298N and logic-level control from the microcontroller.

---
