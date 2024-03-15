#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 6

// package id and its weight
struct package
{
    char *id;
    int weight;
};
typedef struct package package;

// postoffice has each package's min and max weight and count of packages
struct post_office
{
    int min_weight;
    int max_weight;
    package *packages;
    int packages_count;
};
typedef struct post_office post_office;

// town has its name and number of post offices it has and packages of the respective
// post offices
struct town
{
    char *name;
    post_office *offices;
    int offices_count;
};
typedef struct town town;

// it will print down all the packages town->office[i]->packages[j]->id
void print_all_packages(town t)
{
    // print town-name
    printf("%s:\n", t.name);

    for (int i = 0; i < t.offices_count; i++)
    { // print office-Count
        printf("\t%d:\n", i);
        for (int j = 0; j < t.offices[i].packages_count; j++)
            // print package-Id
            printf("\t\t%s\n", t.offices[i].packages[j].id);
    }
}

// this function will check the condition of weight-check and if passed then transfer
// packages source to target
void send_all_acceptable_packages(town *source, int source_office_index, town *target, int target_office_index)
{
    int n = 0; //pc of target office
    // go till source-pack_count
    // check source->package[i]->weight with target->package[i]->weight
    // if succeds then dec source size by n and increase target size by n
    for (int i = 0; i < source->offices[source_office_index].packages_count; i++)
        if (source->offices[source_office_index].packages[i].weight >= target->offices[target_office_index].min_weight &&
            source->offices[source_office_index].packages[i].weight <= target->offices[target_office_index].max_weight)
            ++n;

    //made new struct pointer of new updated sizes
    package *newPackages = malloc(sizeof(package) * (n + target->offices[target_office_index].packages_count));
    package *oldPackages = malloc(sizeof(package) * (source->offices[source_office_index].packages_count - n));

    //transfer the new data into newpackages[index]
    for (int i = 0; i < target->offices[target_office_index].packages_count; i++)
        // transfer the data from target to new package
        newPackages[i] = target->offices[target_office_index].packages[i];

    //upgrade the package count caz we add the package
    n = target->offices[target_office_index].packages_count;
    
    int m = 0; //pc of source office
    
    //now we have to linked that new package into newpakcage struct pointer
    for (int i = 0; i < source->offices[source_office_index].packages_count; i++)
        if (source->offices[source_office_index].packages[i].weight >= target->offices[target_office_index].min_weight &&
            source->offices[source_office_index].packages[i].weight <= target->offices[target_office_index].max_weight)
        {
            newPackages[n] = source->offices[source_office_index].packages[i];
            ++n;
        }
        else
        {
            //we will not take the last data into oldpackage
            oldPackages[m] = source->offices[source_office_index].packages[i];
            ++m;
        }
    
    //now update the package size of target package count
    target->offices[target_office_index].packages_count = n;

    //free the memory that target has
    free(target->offices[target_office_index].packages);

    //update the packages of newly target office
    target->offices[target_office_index].packages = newPackages;

    //now update the package size of source package count
    source->offices[source_office_index].packages_count = m;

    //free the memory source has 
    free(source->offices[source_office_index].packages);

    //update the packages of newly source office    
    source->offices[source_office_index].packages = oldPackages;
}

//to count the number of packages each town has 
int number_of_packages(town t)
{
    int num = 0;
    //get into every offices and count the packages
    for (int i = 0; i < t.offices_count; i++)
        num += t.offices[i].packages_count;
    return num;
}

//to compare the number of packages bw number of town
town town_with_most_packages(town *towns, int towns_count)
{
    int ans;
    int max_packages = -1;
    
    for (int i = 0; i < towns_count; i++)
        if (number_of_packages(towns[i]) > max_packages)
        {
            max_packages = number_of_packages(towns[i]);
            ans = i;
        }
    return towns[ans];
}

//traverse with the every town name and compare the string
town *find_town(town *towns, int towns_count, char *name)
{
    //check till the number of towns_count
    for (int i = 0; i < towns_count; i++)
        if (!strcmp(towns[i].name, name))
            return &(towns[i]);
    //return the address of the name given
    return &towns[0];
}

int main()
{
    int towns_count;
    printf("\nEnter number of towns : ");
    scanf("%d", &towns_count);
    town *towns = malloc(sizeof(town) * towns_count);
    for (int i = 0; i < towns_count; i++)
    {
        towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
        printf("\nEnter name of the town : ");
        scanf("%s", towns[i].name);
        printf("\nEnter office count of %s : ", towns[i].name);
        scanf("%d", &towns[i].offices_count);
        towns[i].offices = malloc(sizeof(post_office) * towns[i].offices_count);
        for (int j = 0; j < towns[i].offices_count; j++)
        {
            printf("\nEnter package count of office\t + Min Weight accepted\t + MaxWeight accepted : \n");
            scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
            towns[i].offices[j].packages = malloc(sizeof(package) * towns[i].offices[j].packages_count);
            for (int k = 0; k < towns[i].offices[j].packages_count; k++)
            {
                towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
                printf("\nEnter id & weight of the package : ");
                scanf("%s", towns[i].offices[j].packages[k].id);
                scanf("%d", &towns[i].offices[j].packages[k].weight);
            }
        }
    }
    int queries;
    printf("\nEnter Query : ");
    scanf("%d", &queries); // this many times switch case will run
    char town_name[MAX_STRING_LENGTH];
    while (queries--)
    {
        int type;
        printf("SELECT OPTION \n1.Print all packages\n2.Send all acceptable packages\n3.Town with the most number of packages\n");
        scanf("%d", &type);
        switch (type)
        {
        case 1:
            printf("\nEnter town's name whose packages you want to print : ");
            scanf("%s", town_name);
            town *t = find_town(towns, towns_count, town_name);
            print_all_packages(*t);
            break;
        case 2:
            printf("\nEnter Source town name : ");
            scanf("%s", town_name);
            town *source = find_town(towns, towns_count, town_name);
            int source_index;
            printf("\nEnter source office index from which you want to send : ");
            scanf("%d", &source_index);
            printf("\nEnter target office name where package is to be deliver : ");
            scanf("%s", town_name);
            town *target = find_town(towns, towns_count, town_name);
            int target_index;
            printf("\nEnter target office index : ");
            scanf("%d", &target_index);
            send_all_acceptable_packages(source, source_index, target, target_index);
            break;
        case 3:
            printf("Town with the most number of packages is %s\n\n", town_with_most_packages(towns, towns_count).name);
            break;
        }
    }
    return 0;
}