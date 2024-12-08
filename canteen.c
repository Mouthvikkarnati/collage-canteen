#include <stdio.h>
#include <ctype.h> 

int main()
{
    int choice, quantity, total_cost = 0, amount_received, remaining_amount;
    char menu_type;

    printf("================================================\n");
    printf("||                                            ||\n");
    printf("||         Welcome to the College Canteen     ||\n");
    printf("||                                            ||\n");
    printf("||   What would you like?                     ||\n");
    printf("||  (D for Drink, F for Food, E to Exit):     ||\n");
    printf("||                                            ||\n");
    printf("================================================\n");

    while (1)
    {
        printf("Enter your MENU choice (D for Drink, F for Food, E to Exit): ");
        scanf(" %c", &menu_type);
        menu_type = toupper(menu_type);

        if (menu_type == 'E') 
        {
            printf("Exiting... Thank you for visiting!\n");
            return 0;
        }

        if (menu_type == 'D') 
        {
            printf("======================================================\n");
            printf("||                                                  ||\n");
            printf("||                Drink Menu                        ||\n");
            printf("||          1. Coffee        10/-                   ||\n");
            printf("||          2. Tea            5/-                   ||\n");
            printf("||          3. Milk           5/-                   ||\n");
            printf("||          4. Water Bottle  20/-                   ||\n");
            printf("||          5. Cool Drink    20/-                   ||\n");
            printf("||                                                  ||\n");
            printf("|| Enter 0 to finish your drink order or E to Exit. ||\n");
            printf("||                                                  ||\n");
            printf("======================================================\n");

            while (1)
            {
                printf("Enter drink item number : ");
                char drink_input;
                scanf(" %c", &drink_input);

                if (toupper(drink_input) == 'E') 
                {
                    printf("Exiting... Thank you for visiting!\n");
                    return 0;
                }

                choice = drink_input - '0';
                if (choice == 0)
                    break;

                if (choice < 1 || choice > 5) 
                {
                    printf("Invalid drink item number. Please try again.\n");
                    continue;
                }

                printf("Enter the quantity for item %d : ", choice);
                char qty_input;
                scanf(" %c", &qty_input);

                if (toupper(qty_input) == 'E') 
                {
                    printf("Exiting... Thank you for visiting!\n");
                    return 0;
                }

                quantity = qty_input - '0';
                int drink_prices[] = {0, 10, 5, 5, 20, 20};
                total_cost += drink_prices[choice] * quantity;
                printf("%d x Item %d added to your order.\n", quantity, choice);
            }
        }
        else if (menu_type == 'F') 
        {
            printf("======================================================\n");
            printf("||                                                  ||\n");
            printf("||                Food Menu                         ||\n");
            printf("||          1. Patty         30/-                   ||\n");
            printf("||          2. Pizza         40/-                   ||\n");
            printf("||          3. Burger        50/-                   ||\n");
            printf("||                                                  ||\n");
            printf("|| Enter 0 to finish your food order or E to Exit. ||\n");
            printf("||                                                  ||\n");
            printf("======================================================\n");

            while (1)
            {
                printf("Enter food item number : ");
                char food_input;
                scanf(" %c", &food_input);

                if (toupper(food_input) == 'E') 
                {
                    printf("Exiting... Thank you for visiting!\n");
                    return 0;
                }

                choice = food_input - '0';
                if (choice == 0)
                    break;

                if (choice < 1 || choice > 3) 
                {
                    printf("Invalid food item number. Please try again.\n");
                    continue;
                }

                printf("Enter the quantity for item %d : ", choice);
                char qty_input;
                scanf(" %c", &qty_input);

                if (toupper(qty_input) == 'E') 
                {
                    printf("Exiting... Thank you for visiting!\n");
                    return 0;
                }

                quantity = qty_input - '0';
                int food_prices[] = {0, 30, 40, 50};
                total_cost += food_prices[choice] * quantity;
                printf("%d x Item %d added to your order.\n", quantity, choice);
            }
        }
        else
        {
            printf("Invalid menu choice. Please enter D for Drink, F for Food, or E to Exit.\n");
            continue; 
        }

        printf("\nWould you like to continue ordering from another menu? (Y for Yes, N for No): ");
        char continue_order;
        scanf(" %c", &continue_order);
        continue_order = toupper(continue_order);

        if (continue_order == 'N')
        {
            break;
        }
    }

    printf("\nYour total cost is: %d/-\n", total_cost);

    remaining_amount = total_cost;

    while (remaining_amount > 0)
    {
        printf("Enter the amount received: ");
        scanf("%d", &amount_received);

        if (amount_received < remaining_amount) 
        {
            remaining_amount -= amount_received;
            printf("You still need to pay %d/- more.\n", remaining_amount);
        }
        else if (amount_received > remaining_amount) 
        {
            printf("You have entered more money. Please collect the change: %d/-\n", amount_received - remaining_amount);
            remaining_amount = 0; 
        }
        else
        {
            printf("Amount received. Thank you for your order!\n");
            remaining_amount = 0; 
        }
    }

    return 0;
}
