<!--
  ╔═════════════════════════════════════════╗
  ║          Rasaalaya README              ║
  ╚═════════════════════════════════════════╝
-->

<p align="center">
  <img src="static/images/logo.png" alt="Rasaalaya Logo" width="100"/>
  <h1 align="center">Rasaalaya</h1>
  <p align="center">🍽️ Your go-to Flask-powered restaurant listing & ordering platform</p>
</p>

---

## 🏷️ Badges

[![Python](https://img.shields.io/badge/python-3.12-blue.svg)](https://www.python.org/)  
[![Flask](https://img.shields.io/badge/flask-2.1.1-lightgrey.svg)](https://flask.palletsprojects.com/)  
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)  
[![Repo Size](https://img.shields.io/github/repo-size/Adyaprana/Rasaalaya)](https://github.com/Adyaprana/Rasaalaya)

---

## 📖 Table of Contents

- [About](#about)  
- [Features](#features)  
- [Tech Stack](#tech-stack)  
- [Demo](#demo)  
- [Getting Started](#getting-started)  
  - [Prerequisites](#prerequisites)  
  - [Installation](#installation)  
  - [Running Locally](#running-locally)  
- [Project Structure](#project-structure)  
- [Screenshots](#screenshots)  
- [Configuration & Customization](#configuration--customization)  
- [Contributing](#contributing)  
- [License](#license)  
- [Author](#author)  

---

## 🧐 About

Rasaalaya is a full-featured, responsive web application built with Flask, designed to help users browse restaurants by cuisine, view detailed menus with images, place food orders, and reserve tables. It combines elegant UI/UX (including light/dark modes), dynamic Jinja2 templates, and an intuitive ordering workflow—all in a single codebase.

---

## ✨ Features

- **Restaurant Listings**: Browse by cuisine category or view all restaurants.  
- **Dynamic Menus**: Each restaurant page displays menu items with images, descriptions, prices, and ratings.  
- **Order Workflow**:  
  1. Select food items from a consolidated “Order Now” menu.  
  2. Fill in name, quantity, and address.  
  3. View a summary on a success page.  
- **Table Reservations**: Reserve tables via a simple form with date/time picker.  
- **Community Forum**: Post, read, and comment on food discussions.  
- **Responsive Design**: Mobile-first grid and flex layouts, premium hover/transition effects.  
- **Theme Toggle**: Light and dark modes with preference saved in `localStorage`.  
- **Secure & Clean Code**: Follows Flask best practices, uses `.gitignore` to exclude sensitive or bulky files.

---

## 🛠️ Tech Stack

- **Backend**: Python 3.12, Flask 2.1.1  
- **Frontend**: HTML5, CSS3 (with modern Flexbox & Grid), JavaScript  
- **Templating**: Jinja2  
- **Data Storage**: SQLite (configurable to other DBs)  
- **Version Control**: Git & GitHub  
- **Dev Tools**: VSCode / PyCharm, Prettier (for CSS/JS formatting)

---

## 🎬 Demo

<!-- If you have a live URL, link it here -->
[🔗 Live Demo](#) • [▶️ Demo Video](#)

---

## 🚀 Getting Started

### Prerequisites

- Python 3.7+  
- Git  
- (Optional) Virtual environment tool (venv, pipenv, etc.)

### Installation

```bash
# 1. Clone the repo
git clone https://github.com/Adyaprana/Rasaalaya.git
cd Rasaalaya

# 2. Create a virtual environment
python -m venv venv
# Windows
venv\Scripts\activate
# macOS/Linux
source venv/bin/activate

# 3. Install dependencies
pip install -r requirements.txt
