/*########################################################
## COP4610 – Principles of Operating Systems – Summer C 2016
## Prof. Jose F. Osorio
## Group: Invictus
## Group Members: Manuel Garcia – 5628720
##                Emmanuel Gonzalez – 2653686
## Project: Virtual Memory Management
## Specs:
## Due Date: 07/30/2016 by 11:55pm
## Module Name:
##
## We Certify that this program code has been written by us
## and no part of it has been taken from any sources.
#########################################################*/


/* linux/mm_types.h -> represetns every physical page on the system with the page struct
 * linux/pagge-flags.h -> contains bit flags for showing locked or dirty pages in Memory
 *        _count filed store the usage count of the page
 *        kernel checks this field indirectly via page_count() function which take a page struct as a parameter
 * page structure is associated with physical pages not virtual pages
 * linux/mmzone.h -> has struct zone which describes memory zones
 * zones are pages of memory with similar properties
 * linux/gfp.h -> interface for requesting memory
 *      page manipulation funcionts page_addres, __get_free_pages
 *
 */

/*
1.the current number of free pages (over all memory zones);                             -> linux/mmzone.h -> zone struct -> free pages
2.the current number of pages used by slab allocator (over all memory zones);
3.the current number of pages in the active list (over all memory zones);               -> linux/mmzone.h -> zone struct->active_list
4.the current number of pages in the inactive list (over all memory zones);             -> linux/mmzone.h -> zone struct->inactive_list
5.the current number of pages in the active list whose reference bits are set (over all memory zones); -> linux
6.the current number of pages in the inactive list whose reference bits are set (over all memory zones); ->
7.the cumulative number of pages moved from the active list to the inactive list (since the last machine boot);
8.the cumulative number of pages evicted from the inactive list (since the last machine boot);
*/

#include <linux/mm_types.h>
#include <linux/page-flags.h>
#include <linux/mmzone.h>
#include <linux/gfp.h>

int main(int argc, char* argv[]){


}
