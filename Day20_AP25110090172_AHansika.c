#include <stdio.h>

#define MAX_PRODUCTS 20
#define RACK_ROWS 3
#define RACK_COLS 3

// Global arrays
int productIDs[MAX_PRODUCTS];
int quantities[MAX_PRODUCTS];
int prices[MAX_PRODUCTS];
int rackMatrix[RACK_ROWS][RACK_COLS];
int productCount = 0;

// Function declarations
void addProduct();
void searchProduct();
void updateQuantity();
void generateRackReport();
void calculateStockValue();
void displayAllProducts();
void displayMenu();

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addProduct(); break;
            case 2: searchProduct(); break;
            case 3: updateQuantity(); break;
            case 4: generateRackReport(); break;
            case 5: calculateStockValue(); break;
            case 6: displayAllProducts(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while(choice != 7);
    return 0;
}

void displayMenu() {
    printf("\n--- Smart Warehouse Analytics System ---\n");
    printf("1. Add Product\n");
    printf("2. Search Product\n");
    printf("3. Update Quantity\n");
    printf("4. Generate Rack Report\n");
    printf("5. Calculate Stock Value\n");
    printf("6. Display All Products\n");
    printf("7. Exit\n");
}

void addProduct() {
    if(productCount >= MAX_PRODUCTS) {
        printf("Warehouse is full. Cannot add more products.\n");
        return;
    }
    int id, qty, price;
    printf("Enter Product ID: ");
    scanf("%d", &id);
    // Check for duplicate ID
    for(int i = 0; i < productCount; i++) {
        if(productIDs[i] == id) {
            printf("Product ID already exists. Cannot add duplicate.\n");
            return;
        }
    }
    printf("Enter Quantity: ");
    scanf("%d", &qty);
    printf("Enter Price: ");
    scanf("%d", &price);
    if(qty <= 0 || price <= 0) {
        printf("Quantity and price must be positive.\n");
        return;
    }
    productIDs[productCount] = id;
    quantities[productCount] = qty;
    prices[productCount] = price;
    productCount++;
    printf("Product added successfully.\n");
}

void searchProduct() {
    int id, found = 0;
    printf("Enter Product ID to search: ");
    scanf("%d", &id);
    for(int i = 0; i < productCount; i++) {
        if(productIDs[i] == id) {
            printf("Product found:\n");
            printf("ID: %d, Quantity: %d, Price: %d\n", productIDs[i], quantities[i], prices[i]);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Not Found\n");
    }
}

void updateQuantity() {
    int id, choice, change;
    printf("Enter Product ID: ");
    scanf("%d", &id);
    for(int i = 0; i < productCount; i++) {
        if(productIDs[i] == id) {
            printf("1. Increase stock\n2. Decrease stock\nEnter choice: ");
            scanf("%d", &choice);
            printf("Enter change in quantity: ");
            scanf("%d", &change);
            if(choice == 1) {
                quantities[i] += change;
                printf("Stock increased.\n");
            } else if(choice == 2) {
                if(quantities[i] - change < 0) {
                    printf("Cannot decrease below zero.\n");
                } else {
                    quantities[i] -= change;
                    printf("Stock decreased.\n");
                }
            } else {
                printf("Invalid choice.\n");
            }
            return;
        }
    }
    printf("Product not found.\n");
}

void generateRackReport() {
    int max = rackMatrix[0][0], min = rackMatrix[0][0];
    int maxRow = 0, maxCol = 0, minRow = 0, minCol = 0;
    int total = 0;
    printf("Enter rack matrix values (3x3):\n");
    for(int i = 0; i < RACK_ROWS; i++) {
        for(int j = 0; j < RACK_COLS; j++) {
            printf("Enter value for rack[%d][%d]: ", i, j);
            scanf("%d", &rackMatrix[i][j]);
            total += rackMatrix[i][j];
            if(rackMatrix[i][j] > max) {
                max = rackMatrix[i][j];
                maxRow = i;
                maxCol = j;
            }
            if(rackMatrix[i][j] < min) {
                min = rackMatrix[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }
    printf("Maximum stock: %d at (%d, %d)\n", max, maxRow, maxCol);
    printf("Minimum stock: %d at (%d, %d)\n", min, minRow, minCol);
    printf("Total items across racks: %d\n", total);
}

void calculateStockValue() {
    int maxVal = 0, minVal = 999999, maxID = -1, minID = -1;
    int totalValue = 0;
    printf("Stock Value Report:\n");
    for(int i = 0; i < productCount; i++) {
        int value = quantities[i] * prices[i];
        printf("ID: %d, Quantity: %d, Price: %d, StockValue: %d\n", productIDs[i], quantities[i], prices[i], value);
        totalValue += value;
        if(value > maxVal) {
            maxVal = value;
            maxID = productIDs[i];
        }
        if(value < minVal) {
            minVal = value;
            minID = productIDs[i];
        }
    }
    printf("Highest stock value: %d (Product ID: %d)\n", maxVal, maxID);
    printf("Lowest stock value: %d (Product ID: %d)\n", minVal, minID);
    printf("Total warehouse value: %d\n", totalValue);
}

void displayAllProducts() {
    printf("ID\tQuantity\tPrice\tStockValue\n");
    for(int i = 0; i < productCount; i++) {
        int value = quantities[i] * prices[i];
        printf("%d\t%d\t\t%d\t%d\n", productIDs[i], quantities[i], prices[i], value);
    }
}
