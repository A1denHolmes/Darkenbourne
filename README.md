# Darkenbourne

**Unreal Engine 5.4**


Этот пет-проект был вдохновлён такими играми, как Dungeonborne и Dark and Darker, о чём можно догадаться из названия.  
Однако мы решили отойти от привычного Dungeon Crawler'а и сделать онлайн-игру в жанре Extraction RPG с видом от третьего лица и боевой системой с референсом на For Honor.

На данном этапе разработки реализованы базовые элементы перемещения, анимации:  
* Анимация ожидания / поворот на месте
* Ходьба
* Анимации прыжка / падения / приземления
* Aim offset
* Legs IK
* Динамическая прозрачность материала персонажа: при приближении камеры к персонажу тот становится частично прозрачным, чтобы не мешать обзору игрока

Используется Enhanced Input System.  
Меш персонажа является плейсхолдером (используется стандартный Lyra персонаж)

Сейчас идёт работа над реализацией спринта и подтягивания с использованием плагина Gameplay Ability System. Планируется использовать его для имплементации всех способностей персонажей.

#
Контроль версий выполняется в Perforce Helix, но я буду также обновлять и репозиторый на GitHub
