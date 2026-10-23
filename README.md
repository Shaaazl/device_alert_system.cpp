# OOP in C++ – Assignment 1

Three console programs written in C++ for the **Object Oriented Programming (CC1022)** course at the University of Management and Technology (UMT), BS Cybersecurity. Each program models a real-world system with classes, encapsulation, input validation and constructor overloading.

## Concepts Covered

- Classes and objects
- Encapsulation (private data, public getters and setters)
- Input validation inside setters, with safe default values
- Default, parameterized and overloaded constructors
- Constructors that call setters, so validation always runs

## Repository Structure

```
oop-cpp-assignment-1/
├── README.md
├── device_alert_system.cpp
├── online_store.cpp
└── parking_lot.cpp
```

## Programs

| File | System | Classes |
|---|---|---|
| `device_alert_system.cpp` | Network security | `Device`, `alert` |
| `online_store.cpp` | Online shop | `product`, `coupon` |
| `parking_lot.cpp` | Parking management | `parkingslot`, `vehicle` |

### 1. Device and Alert System (`device_alert_system.cpp`)

Models devices on a network and the security alerts they raise.

- **Device** stores an IP address, an operating system and a status (`online` or `blocked`). Empty text and invalid statuses are rejected. It has four constructors (default, IP only, IP + OS, and all three values) and a `show()` function.
- **alert** stores an alert ID (greater than 0), a severity level (1 to 5) and a description (not empty). It has four constructors (default, ID only, ID + severity, and all three values).

### 2. Online Store (`online_store.cpp`)

Models products for sale and discount coupons.

- **product** stores a product code, name, price (greater than 0) and stock (not negative). It can show its details, check whether it is in stock, and `sell()` a number of units, reducing stock only when enough is available. It has a default, a parameterized and an overloaded constructor (code and name only).
- **coupon** stores a coupon code, a discount percentage (1 to 90) and an expiry year. It can show its details and check whether it is still valid.

### 3. Parking Lot (`parking_lot.cpp`)

Models parking slots and the vehicles that use them.

- **parkingslot** stores a slot number (greater than 0), a floor number (not negative) and a status (`free` or `occupied`). It can be occupied, released and show its details. It has a default, a parameterized and an overloaded constructor (slot number only).
- **vehicle** stores a plate number, a type (`car` or `bike`) and an hourly charge (greater than 0). It can show its details and `calculatecharge(hours)` for a given number of hours.

## How to Compile and Run

Requires a C++ compiler such as `g++`.

```bash
g++ parking_lot.cpp -o parking_lot
./parking_lot
```

On Windows PowerShell, run `.\parking_lot` instead. Replace the file name to run the other programs.

## Validation Behaviour

When a setter receives an invalid value, it prints a message and stores a safe default instead. For example, an invalid slot number is stored as `1`, and an invalid price is stored as `1.0`.

## Author

**Your Name**
BS Cybersecurity, University of Management and Technology (UMT), Lahore
