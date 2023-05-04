#  WayFin
Simple pathfinding in c.

Default grid size determined by "as" which is equal to 6 by default.
   
    #define as 6
Default map is defined in main function.

    char  map[as][as] = {

		{'X', '0', '#', '0', '0', '0'},
		{'0', '0', '#', '#', '#', '0'},
		{'0', '0', '#', '0', '0', '0'},
		{'0', '0', '#', '0', '#', '0'},
		{'0', '0', '0', '0', '#', '0'},
		{'0', '0', '0', '0', '#', 'Y'}
	};

X is for starting position.
Y is for end position,
#'s are for barrier blocks.
0's are for available pathes.

* Program counts every box arround it latest cache number and finds distance of every block to x.
* To mark the path it traces back from Y and founds the smallest number arround it untill it finds x.

   

## Developement Status
Latest Release: v1.1 (May, 2023)
## Lisence
This project is lisenced by **MIT** lisence as stated in **LICENSE**
