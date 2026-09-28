#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <limits>

using namespace std;

// ============================================================
// PINTEREST - THE EVOLUTION OF VISUAL DISCOVERY
// ============================================================

// -------------------------
// Pin Structure
// -------------------------
struct Pin
{
    string title;
    string author;
    string description;
    string category;
    string tags;
};

// -------------------------
// Convert text to lowercase
// -------------------------
string toLowerCase(string text)
{
    transform(text.begin(), text.end(), text.begin(),
              [](unsigned char c)
              {
                  return tolower(c);
              });

    return text;
}


// -------------------------
// Display a line
// -------------------------
void line()
{
    cout << "------------------------------------------------------------\n";
}

// ============================================================
// PIN DATABASE
// ============================================================

vector<Pin> pins =
{
    // ART & DESIGN
    {
        "Modern Poster Inspiration",
        "Alex Rivera",
        "A collection of modern poster designs with bold typography and creative layouts.",
        "Art & Design",
        "poster, graphic design, modern, inspiration"
    },

    {
        "Creative Layout Ideas",
        "Design Studio",
        "Creative layout ideas for posters, magazines and digital content.",
        "Art & Design",
        "layout, design, poster, graphic design"
    },

    {
        "Minimalist Graphic Design",
        "Studio Minimal",
        "Simple and clean graphic design inspiration using typography and shapes.",
        "Art & Design",
        "minimalist, graphic design, typography"
    },

    {
        "Branding Inspiration",
        "Creative Works",
        "Visual branding ideas including logos, colours and identity systems.",
        "Art & Design",
        "branding, logo, identity, design"
    },

    // TRAVEL
    {
        "Travel Photography",
        "Jenna Lee",
        "Beautiful travel photography ideas for documenting memorable journeys.",
        "Travel",
        "travel photography, photography, vacation"
    },

    {
        "Tropical Vacation Ideas",
        "Wanderlust",
        "Ideas and inspiration for a relaxing tropical vacation.",
        "Travel",
        "vacation, tropical, beach, travel"
    },

    {
        "Travel Itinerary Inspiration",
        "Travel Planner",
        "Creative ideas for planning and organizing your next trip.",
        "Travel",
        "itinerary, travel planning, trip"
    },

    {
        "City Exploration",
        "Urban Explorer",
        "Discover interesting cities, architecture and urban destinations.",
        "Travel",
        "city, architecture, destination"
    },

    // FASHION
    {
        "Minimalist Outfit Ideas",
        "Style Studio",
        "Simple and elegant outfit inspiration for everyday fashion.",
        "Fashion",
        "fashion, outfit, minimalist, style"
    },

    {
        "Streetwear Inspiration",
        "Urban Style",
        "Modern streetwear outfits combining comfort and contemporary style.",
        "Fashion",
        "streetwear, outfit, urban, style"
    },

    {
        "Summer Fashion",
        "Fashion Daily",
        "Fresh and comfortable fashion ideas for the summer season.",
        "Fashion",
        "summer, fashion, outfit, style"
    },

    {
        "Accessory Styling Ideas",
        "Style Guide",
        "Ideas for styling accessories with different outfits.",
        "Fashion",
        "accessories, fashion, styling"
    },

    // PHOTOGRAPHY
    {
        "Nature Photography",
        "Lens Explorer",
        "Photography inspiration for capturing plants, landscapes and nature.",
        "Photography",
        "nature, photography, landscape"
    },

    {
        "Portrait Photography Ideas",
        "Visual Stories",
        "Creative portrait photography ideas using lighting and composition.",
        "Photography",
        "portrait, photography, lighting"
    },

    {
        "Photography Composition",
        "Frame Studio",
        "Composition techniques for creating visually interesting photographs.",
        "Photography",
        "composition, photography, camera"
    },

    {
        "Creative Photo Poses",
        "Photo Ideas",
        "Creative posing ideas for portraits and lifestyle photography.",
        "Photography",
        "poses, portrait, photography"
    },

    // FOOD
    {
        "Easy Recipe Ideas",
        "Kitchen Inspiration",
        "Simple and creative recipe ideas for everyday meals.",
        "Food",
        "recipe, cooking, food, easy"
    },

    {
        "Dessert Inspiration",
        "Sweet Studio",
        "Beautiful dessert ideas including cakes, pastries and sweet treats.",
        "Food",
        "dessert, cake, food, sweet"
    },

    {
        "Food Photography",
        "Food Visuals",
        "Ideas for creating attractive food photography and presentation.",
        "Food",
        "food photography, styling, food"
    },

    {
        "Healthy Meal Ideas",
        "Fresh Kitchen",
        "Colourful and creative healthy meal inspiration.",
        "Food",
        "healthy, meal, food, recipe"
    },

    // INTERIOR DESIGN
    {
        "Cozy Home Interior",
        "Home Living",
        "Warm and comfortable interior design ideas for modern homes.",
        "Interior Design",
        "interior, home, cozy, design"
    },

    {
        "Minimalist Bedroom",
        "Modern Home",
        "Minimalist bedroom ideas using clean layouts and neutral colours.",
        "Interior Design",
        "bedroom, minimalist, interior"
    },

    {
        "Modern Living Room",
        "Interior Ideas",
        "Modern living room designs with stylish furniture and layouts.",
        "Interior Design",
        "living room, modern, interior"
    },

    {
        "Small Space Design",
        "Space Studio",
        "Creative interior solutions for small homes and apartments.",
        "Interior Design",
        "small space, interior, home"
    }
};


// ============================================================
// RELATED KEYWORDS
// ============================================================

void showRelatedKeywords(string category)
{
    cout << "\nRelated Keywords:\n";

    if (category == "Art & Design")
    {
        cout << "1. Poster\n";
        cout << "2. Layout\n";
        cout << "3. Ideas\n";
        cout << "4. Graphic Design\n";
        cout << "5. Branding\n";
    }
    else if (category == "Travel")
    {
        cout << "1. Travel Photography\n";
        cout << "2. Vacation Ideas\n";
        cout << "3. Travel Tips\n";
        cout << "4. Destination\n";
        cout << "5. Itinerary\n";
    }
    else if (category == "Fashion")
    {
        cout << "1. Fashion Inspiration\n";
        cout << "2. Outfit Ideas\n";
        cout << "3. Streetwear\n";
        cout << "4. Accessories\n";
        cout << "5. Summer Fashion\n";
    }
    else if (category == "Photography")
    {
        cout << "1. Nature Photography\n";
        cout << "2. Portrait\n";
        cout << "3. Composition\n";
        cout << "4. Photo Poses\n";
        cout << "5. Camera Ideas\n";
    }
    else if (category == "Food")
    {
        cout << "1. Recipes\n";
        cout << "2. Desserts\n";
        cout << "3. Food Photography\n";
        cout << "4. Healthy Meals\n";
        cout << "5. Cooking Ideas\n";
    }
    else if (category == "Interior Design")
    {
        cout << "1. Bedroom\n";
        cout << "2. Living Room\n";
        cout << "3. Minimalist Interior\n";
        cout << "4. Small Space\n";
        cout << "5. Home Ideas\n";
    }
}


// ============================================================
// DISPLAY PINS
// ============================================================

void displayPins(vector<int> results)
{
    cout << "\nTop Pins:\n";
    line();

    for (int i = 0; i < results.size(); i++)
    {
        int index = results[i];

        cout << "[" << i + 1 << "] "
             << pins[index].title
             << " — by "
             << pins[index].author
             << "\n";

        cout << "    Category: "
             << pins[index].category
             << "\n";

        cout << "\n";
    }

    line();
}


// ============================================================
// SHOW PIN DETAILS
// ============================================================

void showPinDetails(int pinIndex)
{
    bool viewing = true;

    while (viewing)
    {
        cout << "\n\n";
        cout << "============================================================\n";
        cout << "                      PIN DETAILS\n";
        cout << "============================================================\n";

        cout << "\n";
        cout << "[ " << pins[pinIndex].category << " ]\n\n";

        cout << "Title:\n";
        cout << pins[pinIndex].title << "\n\n";

        cout << "Author:\n";
        cout << pins[pinIndex].author << "\n\n";

        cout << "Description:\n";
        cout << pins[pinIndex].description << "\n\n";

        cout << "Tags:\n";
        cout << pins[pinIndex].tags << "\n";

        line();

        cout << "\nWhat would you like to do?\n\n";

        cout << "1. Save Pin\n";
        cout << "2. Add Comment\n";
        cout << "3. Back to Results\n";

        cout << "\nEnter your choice: ";

        int choice;
        cin >> choice;

        // ----------------------------------------------------
        // SAVE PIN
        // ----------------------------------------------------
        if (choice == 1)
        {
            cout << "\n";
            cout << "Save Pin feature will be connected here.\n";
            cout << "This section will be implemented by the team member\n";
            cout << "responsible for the Save Pin function.\n";
        }

        // ----------------------------------------------------
        // COMMENT
        // ----------------------------------------------------
        else if (choice == 2)
        {
            cin.ignore();

            string comment;

            cout << "\nEnter your comment: ";
            getline(cin, comment);

            cout << "\nYour comment has been recorded:\n";
            cout << "\"" << comment << "\"\n";
        }

        // ----------------------------------------------------
        // BACK
        // ----------------------------------------------------
        else if (choice == 3)
        {
            viewing = false;
        }

        else
        {
            cout << "\nInvalid choice. Please try again.\n";
        }
    }
}


// ============================================================
// SEARCH RESULTS
// ============================================================

void searchResults(string keyword)
{
    bool searching = true;

    while (searching)
    {
        string lowerKeyword = toLowerCase(keyword);

        vector<int> results;

        // Find pins that contain the keyword
        for (int i = 0; i < pins.size(); i++)
        {
            string title = toLowerCase(pins[i].title);
            string description = toLowerCase(pins[i].description);
            string tags = toLowerCase(pins[i].tags);
            string category = toLowerCase(pins[i].category);

            if (title.find(lowerKeyword) != string::npos ||
                description.find(lowerKeyword) != string::npos ||
                tags.find(lowerKeyword) != string::npos ||
                category.find(lowerKeyword) != string::npos)
            {
                results.push_back(i);
            }
        }

        cout << "\n\n";
        cout << "============================================================\n";
        cout << "                 SEARCH RESULTS\n";
        cout << "============================================================\n";

        cout << "\nSearch Results For: " << keyword << "\n";

        // Show related keywords
        cout << "\nRelated Keywords:\n";

        if (lowerKeyword == "design")
        {
            cout << "1. Poster\n";
            cout << "2. Layout\n";
            cout << "3. Ideas\n";
            cout << "4. Graphic Design\n";
            cout << "5. Branding\n";
        }
        else if (lowerKeyword == "fashion")
        {
            cout << "1. Fashion Inspiration\n";
            cout << "2. Outfit Ideas\n";
            cout << "3. Streetwear\n";
            cout << "4. Accessories\n";
        }
        else if (lowerKeyword == "travel")
        {
            cout << "1. Travel Photography\n";
            cout << "2. Vacation Ideas\n";
            cout << "3. Travel Tips\n";
            cout << "4. Destination\n";
        }
        else if (lowerKeyword == "food")
        {
            cout << "1. Recipes\n";
            cout << "2. Desserts\n";
            cout << "3. Food Photography\n";
            cout << "4. Healthy Meals\n";
        }
        else
        {
            cout << "Explore more ideas related to \"" << keyword << "\".\n";
        }

        // Show matching pins
        if (results.empty())
        {
            cout << "\nNo pins were found for \"" << keyword << "\".\n";
        }
        else
        {
            displayPins(results);
        }

        cout << "\n";
        cout << "Options:\n";
        cout << "1. Explore a Pin\n";
        cout << "2. Search Again\n";
        cout << "3. Back to Main Page\n";

        cout << "\nEnter your choice: ";

        int choice;
        cin >> choice;

        // ----------------------------------------------------
        // EXPLORE PIN
        // ----------------------------------------------------
        if (choice == 1)
        {
            if (results.empty())
            {
                cout << "\nThere are no pins available to explore.\n";
            }
            else
            {
                int pinChoice;

                cout << "\nEnter the pin number to explore: ";
                cin >> pinChoice;

                if (pinChoice >= 1 &&
                    pinChoice <= results.size())
                {
                    showPinDetails(results[pinChoice - 1]);
                }
                else
                {
                    cout << "\nInvalid pin number.\n";
                }
            }
        }

        // ----------------------------------------------------
        // SEARCH AGAIN
        // ----------------------------------------------------
        else if (choice == 2)
        {
            cin.ignore();

            cout << "\nSearch for: ";
            getline(cin, keyword);
        }

        // ----------------------------------------------------
        // BACK
        // ----------------------------------------------------
        else if (choice == 3)
        {
            searching = false;
        }

        else
        {
            cout << "\nInvalid choice. Please try again.\n";
        }
    }
}


// ============================================================
// CATEGORY EXPLORATION
// ============================================================

void exploreCategory(string category)
{
    bool exploring = true;

    while (exploring)
    {
        vector<int> results;

        // Find pins belonging to category
        for (int i = 0; i < pins.size(); i++)
        {
            if (pins[i].category == category)
            {
                results.push_back(i);
            }
        }

        cout << "\n\n";
        cout << "============================================================\n";
        cout << "                    " << category << "\n";
        cout << "============================================================\n";

        showRelatedKeywords(category);

        cout << "\n";
        displayPins(results);

        cout << "\nOptions:\n";
        cout << "1. Explore a Pin\n";
        cout << "2. Search within this category\n";
        cout << "3. Back to Main Page\n";

        cout << "\nEnter your choice: ";

        int choice;
        cin >> choice;

        // ----------------------------------------------------
        // EXPLORE PIN
        // ----------------------------------------------------
        if (choice == 1)
        {
            int pinChoice;

            cout << "\nEnter the pin number to explore: ";
            cin >> pinChoice;

            if (pinChoice >= 1 &&
                pinChoice <= results.size())
            {
                showPinDetails(results[pinChoice - 1]);
            }
            else
            {
                cout << "\nInvalid pin number.\n";
            }
        }

        // ----------------------------------------------------
        // SEARCH
        // ----------------------------------------------------
        else if (choice == 2)
        {
            cin.ignore();

            string keyword;

            cout << "\nSearch for: ";
            getline(cin, keyword);

            searchResults(keyword);
        }

        // ----------------------------------------------------
        // BACK
        // ----------------------------------------------------
        else if (choice == 3)
        {
            exploring = false;
        }

        else
        {
            cout << "\nInvalid choice. Please try again.\n";
        }
    }
}


// ============================================================
// SAVED PINS
// ============================================================

void viewSavedPins()
{
    cout << "\n\n";
    cout << "============================================================\n";
    cout << "                     SAVED PINS\n";
    cout << "============================================================\n";

    cout << "\nYour saved pins will appear here.\n";

    cout << "\nThe Save Pin function will be connected by the\n";
    cout << "team member responsible for the Save Pin section.\n";

    line();

    cout << "\n1. Back to Main Page\n";

    cout << "\nEnter your choice: ";

    int choice;
    cin >> choice;

    if (choice != 1)
    {
        cout << "\nReturning to Main Page...\n";
    }
}


// ============================================================
// MAIN PAGE
// ============================================================

void mainPage()
{
    bool running = true;

    while (running)
    {
        cout << "\n\n";

        cout << "============================================================\n";
        cout << "                  WELCOME TO PINTEREST!\n";
        cout << "============================================================\n";

        cout << "\nWhat would you like to explore today?\n";

        cout << "\n";
        cout << "Search for ideas\n";
        cout << "\n";

        line();

        cout << "\nExplore by Category:\n\n";

        cout << "1. Art & Design              4. Photography\n";
        cout << "2. Travel                    5. Food\n";
        cout << "3. Fashion                   6. Interior Design\n";

        cout << "\n7. View Saved Pins\n";
        cout << "8. Exit\n";

        line();

        cout << "\nEnter a category number or type a search keyword:\n";
        cout << "> ";

        string input;

        getline(cin, input);

        // ----------------------------------------------------
        // CATEGORY SELECTION
        // ----------------------------------------------------

        if (input == "1")
        {
            exploreCategory("Art & Design");
        }

        else if (input == "2")
        {
            exploreCategory("Travel");
        }

        else if (input == "3")
        {
            exploreCategory("Fashion");
        }

        else if (input == "4")
        {
            exploreCategory("Photography");
        }

        else if (input == "5")
        {
            exploreCategory("Food");
        }

        else if (input == "6")
        {
            exploreCategory("Interior Design");
        }

        // ----------------------------------------------------
        // SAVED PINS
        // ----------------------------------------------------

        else if (input == "7")
        {
            viewSavedPins();
        }

        // ----------------------------------------------------
        // EXIT
        // ----------------------------------------------------

        else if (input == "8")
        {
            running = false;
        }

        // ----------------------------------------------------
        // SEARCH
        // ----------------------------------------------------

        else if (!input.empty())
        {
            searchResults(input);
        }

        else
        {
            cout << "\nPlease enter a category number or keyword.\n";
        }
    }
}

int main()
{
    mainPage();

    return 0;
}