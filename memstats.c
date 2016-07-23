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

#include <linux/page-flags.h>
#include <linux/mmzone.h>
#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <linux/memstats.h>
#include <linux/uaccess.h>


asmlinkage long sys_memstats(struct memstats* info){

        // structs
        struct zone* zone;
        struct page* page;
        struct memstats* temp;

        struct list_head* list;
        struct list_head* free_pages;
        struct list_head* active;
        struct list_head* inactive;
        long unsigned int area_length;
        int i;

        //allocating memory for the temporary memstats struct
        temp = (struct memstats*)kmalloc(sizeof(struct memstats), GFP_KERNEL);

        /*Iterate through every zone */
        for_each_zone(zone){

                area_length = sizeof(zone->free_area)/sizeof(struct free_area);

                //iterate through areas in zone
                for(i = 0; i<area_length; i++) {
                        list_for_each(free_pages, &(((struct free_area*)(zone->free_area) + i)->free_list)){

                                temp->num_free_pages++;

                        }
                }

                list_for_each(active, &(zone->active_list)){
                        temp->num_active_pages++;
                        page = list_entry(active, struct page, lru);
                        temp->num_slab_pages += test_bit(PG_slab, &page->flags);
                        temp->num_active_ref_bits += test_bit(PG_referenced, &page->flags) :
                }

                list_for_each(inactive, &(zone->inactive_list)){
                        temp->num_inactive_pages++;
                        page = list_entry(inactive, struct page, lru);
                        temp->num_slab_pages += test_bit(PG_slab, &page->flags);
                        temp->num_inactive_ref_bits += test_bit(PG_referenced, &page->flags) :
                }

        }

        //copying back to user space
        if(copy_to_user(info,temp,sizeof(struct memstats))) {
                return -EFAULT;
        }
        else{
                return 0;
        }



}
