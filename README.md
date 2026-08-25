# simpleHPP (v0.1c) 🚀

> **Language / Язык:**
> 🌍 [English (#english-version)](#simplehpp-v01c-) | 🇷🇺 [Русский (#русская-версия)](#simplehpp-v01c-ru)

---

A polished, lightweight, high-performance single-header utility library for C++ automation scripts, game jams, and fast console prototyping. 

This is an optimized and secured fork of the original `simpleHPP v0.1b` project, rewritten to meet modern C++ performance and safety standards.

---

## 🔥 Key Features & Usage

### 1. High-Performance Random Numbers
Generates pseudo-random integers within a defined range. It uses a `static std::mt19937` engine initialized only once, ensuring maximum speed even when called millions of times per second.

```cpp
// Returns a random number between 1 and 100 (swaps min/max automatically if inverted)
int enemy_hp = simple::randint(1, 100); 
```

### 2. Streamlined Safe Console Input
Solves the infamous C++ bug where residual newline characters (`\n`) left over from `std::cin >>` cause subsequent `std::getline` calls to skip user input.

```cpp
std::string username = simple::input("Enter your nickname: ");
```

### 3. Code Execution Profiler (`Timer`)
A zero-overhead, highly versatile stopwatch class using `<chrono>`. It provides unified measurements in different time intervals and floating-point seconds.

```cpp
simple::Timer t;
t.start();

// ... your heavy code here ...

t.end();
std::cout << "Time elapsed: " << t.getTimeX() << " seconds." << std::endl;
std::cout << "Time in milliseconds: " << t.getTime(simple::TimeUnit::Milliseconds) << " ms" << std::endl;
```

### 4. Non-crashing Progress Bar Generator
Generates a stylized percentage indicator string (`[#####-----] 50%`) with range clamping to ensure the application never aborts unexpectedly.

```cpp
std::cout << simple::genProgressBar(75) << std::endl; // Output: [#######---] 75%
```

### 5. Instant Screen Clearing
Clears the terminal workspace and returns the cursor to the top-left position. It bypasses slow system sub-processes by utilizing modern terminal control codes.

```cpp
simple::ccls(); // Instant, cross-platform refresh
```

---

## 🛠️ Comparison & Upgrades (v0.1b vs v0.1c)

Here is a detailed breakdown of critical issues present in the old `v0.1b` release and how we resolved them in `v0.1c`:

| Feature | Original v0.1b Implementation | Upgraded v0.1c Implementation | Why this matters |
| :--- | :--- | :--- | :--- |
| **`randint()` Engine** | Re-instantiated a heavy `std::mt19937` generator and polled `std::random_device` on **every single call**. | Shifted the random engine to a `static` layout inside the function body. | **Massive performance boost.** Generating numbers in loops no longer chokes the CPU. Added protection against inverted bounds (`min > max`). |
| **`input()` Stability** | Used platform-dependent macros (`#if defined(_WIN32)`) and dangerous loop-bound checking via `std::cin.peek()`. | Cleaned into an elegant, standard-compliant `std::cin` validation that discards `\n` without freezing. | **Fixed execution freezes on Unix (Linux/macOS) systems.** Added state recovery via `std::cin.clear()`. |
| **`Timer` Architecture** | Duplicated code blocks 4 times inside the logic, lacked `const` safety qualifiers, and only returned integers. | Removed duplication using modern type-inference (`auto`) with ternary operators. Added `const` protection and a dedicated `getTimeX()` helper. | **Better code health (DRY) and flexibility.** The timer can now be read by read-only references and returns continuous floating-point seconds (`double`). |
| **`genProgressBar()`** | Contained a typo (`gen_progres_bar`) and strictly terminated the application via `std::abort()` if outside bounds. | Renamed cleanly (`genProgressBar`), removed native `assert`/`abort`, and introduced safe range saturation. | **Application resiliency.** Passing `-5` or `120` to the progress bar will seamlessly clamp to `0` or `100` instead of instantly crashing your app. |
| **`ccls()` Execution** | Ran heavy shell system utilities (`std::system("cls" / "clear")`) that spawn sub-processes. | Swapped to native ANSI escape sequences (`\033[2J\033[H`). | **Security & Speed.** Completely safe from Command Injection vulnerabilities and operates exponentially faster. |

Developed with ❤️ to make basic C++ command workflows easy and reliable.

<br>
<br>
<hr>
<br>
<br>

# simpleHPP (V0.1C) 🇷🇺 [Русская Версия]

Улучшенная, легковесная и высокопроизводительная утилитная библиотека из одного заголовочного файла (`single-header`) для автоматизации скриптов на C++, гейм-джемов и быстрого прототипирования консольных приложений.

Это оптимизированный и безопасный форк оригинального проекта `simpleHPP v0.1b`, переписанный в соответствии с современными стандартами производительности и безопасности C++.

---

## 🔥 Основные возможности и использование

### 1. Высокопроизводительный рандом
Генерирует псевдослучайные целые числа в заданном диапазоне. Использует движок `static std::mt19937`, который инициализируется всего один раз, что обеспечивает максимальную скорость работы, даже если вызывать функцию миллионы раз в секунду.

```cpp
// Возвращает случайное число от 1 до 100 (автоматически меняет min/max местами при инверсии)
int enemy_hp = simple::randint(1, 100); 
```

### 2. Безопасный консольный ввод
Решает знаменитый баг C++, когда остаточные символы новой строки (`\n`), оставшиеся после `std::cin >>`, заставляют последующие вызовы `std::getline` просто пропускать ввод пользователя.

```cpp
std::string username = simple::input("Введите ваш никнейм: ");
```

### 3. Профайлер времени выполнения (`Timer`)
Высокоточный секундомер без накладных расходов, использующий библиотеку `<chrono>`. Предоставляет унифицированные измерения в различных интервалах времени и секундах с плавающей запятой.

```cpp
simple::Timer t;
t.start();

// ... ваш тяжелый код ...

t.end();
std::cout << "Прошло времени: " << t.getTimeX() << " секунд." << std::endl;
std::cout << "Время в миллисекундах: " << t.getTime(simple::TimeUnit::Milliseconds) << " мс" << std::endl;
```

### 4. Безопасный генератор прогресс-бара
Генерирует стилизованную строку индикатора выполнения (`[#####-----] 50%`) с ограничением диапазона, что гарантирует, что приложение никогда аварийно не завершится из-за некорректных процентов.

```cpp
std::cout << simple::genProgressBar(75) << std::endl; // Вывод: [#######---] 75%
```

### 5. Мгновенная очистка экрана
Очищает рабочее пространство терминала и возвращает курсор в верхнюю левую позицию. Работает в обход медленных системных процессов ОС за счет использования современных управляющих кодов терминала.

```cpp
simple::ccls(); // Мгновенное кроссплатформенное обновление
```

---

## 🛠️ Сравнение и улучшения (v0.1b vs v0.1c)

Ниже приведен подробный разбор критических проблем, присутствовавших в старом релизе `v0.1b`, и то, как мы исправили их в `v0.1c`:

| Функция | Реализация в оригинальной v0.1b | Улучшения в версии v0.1c | Почему это важно |
| :--- | :--- | :--- | :--- |
| **Движок `randint()`** | Создавал тяжелый объект `std::mt19937` и опрашивал системный `std::random_device` при **каждом вызове функции**. | Движок генерации перенесен в `static` структуру внутри тела функции. | **Огромный прирост производительности.** Генерация чисел в циклах больше не душит процессор. Добавлена защита от перепутанных границ диапазона (`min > max`). |
| **Стабильность `input()`** | Использовала платформозависимые макросы (`#if defined(_WIN32)`) и опасную логику проверки буфера через `std::cin.peek()`. | Переписана в элегантную, стандартную валидацию потока `std::cin`, которая сбрасывает `\n` без зависаний. | **Исправлены «мертвые» зависания на Unix-системах (Linux/macOS).** Добавлено восстановление состояния потока через `std::cin.clear()`. |
| **Архитектура `Timer`** | Код дублировался 4 раза внутри логики, отсутствовали квалификаторы константной безопасности `const`, возвращались только целые числа. | Дублирование удалено с помощью вывода типов `auto` и тернарных операторов. Добавлена `const`-защита и метод `getTimeX()`. | **Чистота кода (DRY) и гибкость.** Таймер теперь можно считывать по константным ссылкам, и он умеет возвращать непрерывные секунды типа `double`. |
| **`genProgressBar()`** | Содержала орфографическую опечатку (`gen_progres_bar`) и намертво убивала приложение через `std::abort()`, если процент выходил за границы. | Имя исправлено на `genProgressBar`, удалены жесткие `assert`/`abort`, введено мягкое насыщение диапазона. | **Устойчивость приложения.** Передача значений вроде `-5` или `120` аккуратно приведется к `0` или `100` вместо мгновенного вылета всей программы. |
| **Выполнение `ccls()`** | Запускала тяжелые системные утилиты командной строки (`std::system("cls" / "clear")`), порождающие сторонние процессы. | Заменена на прямую отправку встроенных управляющих ANSI-последовательностей (`\033[2J\033[H`). | **Безопасность и скорость.** Полная защита от уязвимостей типа Command Injection, а скорость работы увеличилась в сотни раз. |

Разработано с ❤️, чтобы сделать базовые операции в C++ простыми, быстрыми и надежными.
