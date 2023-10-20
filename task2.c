#include <stdio.h>
#include <string.h>
#include <stdbool.h>


struct User {
    char firstname[30];
    char lastname[30];
    char email[30];
    int  phone[15];
    char username[30];
    char password[30];
    
};

struct User users[100]; 



int Countuser = 0; 



union {
    struct {
       char flag[20];
      
    } flag;
    
   
} u;










void registration() {
 

    if (Countuser < 100) {
        struct User user;
        
        printf("\nEnter a First Name : ");
        scanf("%s", user.firstname);
 
        printf("Enter a Last Name : ");
        scanf("%s", user.lastname);

        printf("Enter a email : ");
        scanf("%s", user.email);

        printf("Enter a phone : "); 
        scanf("%s", user.phone);
        
        printf("Enter a username : ");
        scanf("%s", user.username);

        printf("Enter a password : ");
        scanf("%s", user.password);
        
        printf("Enter a flag ( please Enter True or 1 ===> active  false or 0 ==>not active  ) : ");
        scanf("%s",u.flag.flag);
        
     

       
       
        users[Countuser++] = user;
        printf("\n successful Registration!\n");
         
    } else {
        printf("\nCannot register more users.\n");
    }
  


     
    
}



int login(const char *username, const char *password) {
    for (int i = 0; i < Countuser; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1; 
        }
    }
               
    return 0; 
}

int main() {
    char username[30];
    char password[30];
    int option;
 
        
   
   strcpy(u.flag.activetrue,"true");
   strcpy(u.flag.activefalse,"false");

   
   
    
    while (1) {
        printf("\nPress 1 to Register\nPress 2 to login\nPress 3 to Quit\nEnter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                registration();
              
               
                break;

            case 2:
               
                
                if(strcmp(u.flag.flag,"true") ==0 || strcmp(u.flag.flag,"1")== 0){
                printf("you allow to login \n");
                printf("\nEnter your username : ");
                scanf("%s", username);

                printf("Enter your password : ");
                scanf("%s", password);

                       if (login(username, password)) {
                         printf("\nLogin successful!\n");
                       } else {
                        printf("\nInvalid username or password.\n");
                        }
                }

                else if (strcmp(u.flag.flag,"false") ==0 || strcmp(u.flag.flag,"0")== 0)
                {
                     printf(" you not allow to login  \n "); 
                }
                
               
                
                
                break;

            case 3:
                printf("\nGoodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}