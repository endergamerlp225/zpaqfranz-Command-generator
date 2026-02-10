
#include <stdio.h>

int die(){              // here so i won't repeat that same code over and over again. D.R.Y
    printf("\n Invalid argument, closing program.");
    return 0;
}

int main(){
    int a, method, check, fragment, b;
    char Archive[100] = "Archive_name";
    char command[512] = "zpaqfranz a";
    char *method_str;
    char *checks;
    char *ht_flag;

    printf("\n ssd or hdd? 1 = ssd, 2 = hdd: ");
    scanf("%d", &a);

    if (a == 1) {       // ssd and ht set.
        method_str = "ssd";
        ht_flag = "-ht";
    } else if (a == 2)  {   // hdd
        method_str = "hdd";
    } else {
        die();
    }
    // archive name check below.
    printf("\narchive name? (Use _ instead of spaces) ");
    scanf("%s", Archive);
    printf("\nDEBUG: Your archives name is: ");     // Debug or rather temp prints
    printf("%s", Archive);                          // to be removed later... probably
    // too lazy to remove the debug lines.

    // no/checksum check below.
    printf("\n checksum or nochecksum? 1 = nochecksum, 2 = checksum: ");
    scanf("%d", &check);
    if (check == 1) {
        checks = "-nochecksum";
    } else if (check == 2){
        checks = "";
    } else {
        die();
    }
    printf("Which method do you want? from 1 to 5 only: ");
    scanf("%d", &b);
    if (b < 1 || b > 5){
        die();
    } else {
        printf("fragments to use? 6 is default used by franz btw: ");
        scanf("%d", &fragment);

        snprintf(command, sizeof(command),
            "zpaqfranz a %s-m%d_%s_frag%d.zpaq Directory -m%d %s -%s -verbose -hw %s -fragment %d",
            Archive,
            b,
            checks,
            fragment,
            b,          // method used
            ht_flag,         // only turned on if ssd is.
            method_str, // ssd or hdd
            checks,     // checksum
            fragment
        );
        printf("\nGenerated command:\n%s\n", command);
    }
    return 0;
}

// No directory checks you may ask?
// thats because i'm shit at C
// and can't seem to figure out
// how to assign it to a var
// without getting a SIGSEV
// or some other shit error.
