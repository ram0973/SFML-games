# SFML

### Сборник игр на C++14 и C++17, движки SFML и Box2D

Проверялось в Windows 11 x64

Взяты отсюда
https://www.youtube.com/@FamTrinli

и
https://www.youtube.com/@Kofybrek

### Запуск

Ставим Visual Studio 2022, vcpkg

В vcpkg включаем интеграцию с Visual Studio.

Инструкция здесь:

https://vcpkg.io/en/getting-started

Устанавливаем зависимости в vcpkg:

Cтавим sfml, box2d.

```bash
.\vcpkg\vcpkg install sfml:x64-windows
.\vcpkg\vcpkg install box2d:x64-windows
```

В систему ставим OpenAL для звуков и музыки.

https://www.openal.org/

Открываем SFML.sln

Правой кнопкой на нужный проект - "Назначить в качестве запускаемого проекта"

Запускаем отладчик
