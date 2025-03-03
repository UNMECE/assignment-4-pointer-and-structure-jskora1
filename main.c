#include "item.h" 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index){

//int size_sku = strlen(sku), size_category = strlen(category), size_name = strlen(name);

	item_list[index].price = price;

	item_list[index].sku = (char*)malloc(strlen(sku) + 1);
	strcpy(item_list[index].sku, sku);

	item_list[index].category = (char*)malloc(strlen(category) + 1);
	strcpy(item_list[index].category, category);

	item_list[index].name = (char*)malloc(strlen(name) + 1);
	strcpy(item_list[index].name, name);
}

void free_items(Item *item_list, int size){

free(item_list);
//free(item_list.sku);
//free(item_list.category);
//free(item_list.name);

}

double average_price(Item *item_list, int size)
{
	double price;
	int i;
	item_list[i].price = price;
	double sum = 0;
	double average;
		for (i = 0; i < size; i++)
			{ sum = sum + item_list[i].price;}

			average = sum / size; 
			printf("average price of items = %.2f\n", average); 
}

void print_items(Item *item_list, int size)
{
 	printf("Array outputi: \n");
 	int i; 
	for(i = 0; i < size; i++) {
	//	printf(" %d, %c, %c, %c ", item_list[i].price, item_list[i].sku, item_list[i].category, item_list[i].name);

        printf("  Name: %s\n", item_list[i].name);
        printf("  SKU: %s\n", item_list[i].sku);
        printf("  Category: %s\n", item_list[i].category);
        printf("  Price: $%.2f\n\n", item_list[i].price);
 	}
	
}
int main (int count, char *arg[] ) {

	int size = 5;

	Item *item_list = (Item*)malloc(size * sizeof(Item));

	char *sku = arg[1];


	add_item(item_list, 5.99, "123456", "fruit", "lime", 0);
	add_item(item_list, 10.99, "789012", "eggs", "eggs", 1);
	add_item(item_list, 19.99, "345678", "meat", "steak", 2); 
	add_item(item_list, 29.99, "901234", "drugs", "cough syrup", 3); 
	add_item(item_list, 39.99, "567890", "alcohol", "tequila", 4); 



	
	print_items(item_list, size);
	average_price(item_list, size);
	int i=0;

//	while(strcmp(item_list[i].sku,sku) != 0 && i < size)
//	{
//		printf("Item SKU:%s\n ", item_list[i].sku);
//
//	}	

	//while(i < size && strcmp(item_list[i].sku, sku) != 0 ){
	//	printf("Item SKU:%s\n ", item_list[i].sku);
	//}
	int sku_found = 0;
	while(i < size)
	{
	    if (strcmp(item_list[i].sku, sku) == 0 )
	    {
		printf("Item SKU: %s %s \n", sku, item_list[i].name);
		sku_found = 1;
		break;
	    }	
	    i++;

	}
	if (sku_found == 0)
	{
	    	printf("Item SKU: %s", sku);
		printf(" not found \n");
	}
	free_items(item_list, size);
return 0;
}

