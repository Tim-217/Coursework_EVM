# Курсовая работа по Основам организации ЭВМ, вариант 4
Оценка среднего времени выполнения команды. Конвейер процессора включает в
себя следующие ступени: чтение и дешифрация кода операции, выборка первого операнда,
выборка второго операнда, вычисление результата, запись данных (по адресу второго
операнда). Дешифрация кода операции выполняется за 1 такт. Способы адресации
операндов регистровая и косвенная. Вероятность того, что для данного операнда
используется регистровая адресация P1 (0.9; 0.8; 0.6). Время обращения к регистру 1 такт.
Время обращения к памяти N тактов (2, 5, 10). И код операции, и операнд занимают одно
слово памяти. Поддерживается два типа команд. Вычисление результата для команд
первого типа выполняется за 1 такт, вычисление результата для команд второго типа
выполняется за M тактов (4, 8, 16). Вероятность того, что текущая команда является
командой первого типа P2 (0.9; 0.7; 0.5). В один момент времени может выполняться чтение
из памяти кода операции и обращение к памяти для чтения или записи в память данных.
