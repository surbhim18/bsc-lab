/*
 * Looks for same elements discontinuously
 *                         (in order)
 */


isSublist([],[_|_]) :-!.
/* _ can be anything (not neccessarily list).
 * [_|_] is any list.
 */

isSublist([H|T],[H|T1]) :- isSublist(T,T1),!.

isSublist([H|T],[H1|T1]) :- isSublist([H|T],T1),!.


