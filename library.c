#include<stdio.h>
void printInfo();
void paymentPortal();
void invoice();

struct details
{
    char bookName[40], authorName[20];
    int numberOfCopies, totalPrice;
    float discountTemp, price;
    int  discountGiven, finalPrice;
    long long int cardNumber;
    int pin, count;
}user;

int main()
{

    printf("\n\n\t******WELCOME TO BOOK STORE******\n\n");
    printf("~Enter book details to be purchased\n\n");
    printf("Book name   : ");
    fgets(user.bookName, sizeof(user.bookName), stdin);
    printf("Author name : ");    
    fgets(user.authorName, sizeof(user.authorName), stdin);
    printf("Price       : ");
    scanf("%f", &user.price);
    printf("Number of copies to be purchased : ");
    scanf("%d", &user.numberOfCopies);
    user.totalPrice = user.numberOfCopies * user.price;

    if(user.numberOfCopies < 3)
    {
        user.discountTemp = user.price / 100;
        user.discountGiven = (user.discountTemp * 3) * user.numberOfCopies;
        user.finalPrice = user.totalPrice - user.discountGiven;
    }
    if(user.numberOfCopies <= 10)
    {
        user.discountTemp = user.price / 100;
        if(user.numberOfCopies <= 4)
        {
            user.discountGiven = (user.discountTemp * 15) * user.numberOfCopies;
            user.finalPrice = user.totalPrice - user.discountGiven;
        }
        else if(user.numberOfCopies > 4)
        {
            user.discountGiven = (user.discountTemp * 15) * 4;
            user.finalPrice = user.totalPrice - user.discountGiven;
        }
    }
    if(user.numberOfCopies > 10)
    {
        user.discountTemp = user.price / 100;
        user.discountGiven = (user.discountTemp * 10) * user.numberOfCopies;
        user.finalPrice = user.totalPrice - user.discountGiven;
    }
    printInfo();
    paymentPortal();
    return 0;
}
void printInfo()
{
    printf("\n\n\t\tPricing\n\n");
    printf("Unit price     : %.0f\n", user.price);
    printf("Total Price    : %d\n", user.totalPrice);
    printf("Discount       : %d\n", user.discountGiven);
    printf("Payable amount : %d\n", user.finalPrice);
}
void paymentPortal()
{
    printf("\n\n\t\tCard Info\n\n");
    card:
    printf("Enter card number : ");
    scanf("%lld", &user.cardNumber);
    user.count = 0;
    do
    {   
        user.cardNumber = user.cardNumber / 10; 
        user.count ++;
    }while(user.cardNumber > 0);
    
    if(user.count == 14)
    {
        pin:
        printf("Enter card pin    : ");
        scanf("%d", &user.pin);
        user.count = 0;
        do
        {   
            user.pin = user.pin / 10; 
            user.count ++;
        }while(user.pin > 0);

        if(user.count == 4)
        {
            invoice();
        }
        else
        {
            printf("Invalid Pin\n");
            goto pin;
        }
    }
    else
    {
        printf("Invalid Card Number\n");
        goto card;
    }
    
}
void invoice()
{
    printf("\n\n\t\tINVOICE\n\n");
    printf("Book name    : %s", user.bookName);
    printf("Author       : %s", user.authorName);
    printf("Units Bought : %d\n", user.numberOfCopies);
    printf("Unit Price   : %.0f\n", user.price);
    printf("Total Price  : %d\n", user.totalPrice);
    printf("Discount     : %d\n", user.discountGiven);
    printf("Amount Paid  : %d\n", user.finalPrice);
    printf("\n\n\tPURCHASE SUCCESSFULL\n");
}
