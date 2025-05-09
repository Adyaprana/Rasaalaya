from flask import Flask, render_template, request, jsonify
import json
import os

app = Flask(__name__)

# File to store restaurants data (if not exists, defaults will be used)
DATA_FILE = "restaurants.json"

# Default list of restaurants with food descriptions
default_restaurants = [
    {
        "id": "south-indian",
        "name": "Dakshin Delights",
        "cuisine": "South Indian",
        "description": "Authentic flavors from Tamil Nadu, Kerala, Karnataka, and Andhra Pradesh.",
        "image": "/static/images/south-indian.jpg",
        "rating": 4.7,
        "menu": [
            {
                "name": "Masala Dosa",
                "description": "Crispy rice crepe filled with spicy mashed potatoes, served with chutney and sambar.",
                "price": 180,
                "image": "/static/images/masala_dosa.jpg"
            },
            {
                "name": "Idli Sambar",
                "description": "Soft and fluffy rice cakes served with a flavorful lentil soup and coconut chutney.",
                "price": 120,
                "image": "/static/images/idli_sambar.jfif",
                "veg": True

            },
            {
                "name": "Vada",
                "description": "A popular Indian savory fried snack, also known as a fritter or dumpling.",
                "price": 100,
                "image": "/static/images/vada.jfif",
                "veg": True

            },
            {
                "name": "Pongal",
                "description": "A traditional South Indian breakfast made with rice and lentils, seasoned with black pepper, cumin, and cashews.",
                "price": 150,
                "image": "/static/images/pongal.jpg",
                "veg": True
            },
            {
                "name": "Bisi Bele Bath",
                "description": "A spicy and flavorful rice dish made with lentils, rice, mixed vegetables, and aromatic spices.",
                "price": 200,
                "image": "/static/images/bisi_bele_bath.jpg",
                "veg": True
            },
            {
                "name": "Rava Upma",
                "description": "A savory South Indian breakfast dish made from semolina, vegetables, and spices.",
                "price": 100,
                "image": "/static/images/rava_upma.jpg",
                "veg": True
            }
        ]
    },
    {
        "id": "chinese",
        "name": "Dragon Wok",
        "cuisine": "Chinese",
        "description": "Traditional and modern Chinese cuisine with bold flavors.",
        "image": "/static/images/chinese.avif",
        "rating": 4.5,
        "menu": [
            {
                "name": "Kung Pao Chicken",
                "description": "Stir-fried chicken with peanuts, vegetables, and chili peppers.",
                "price": 280,
                "image": "/static/images/kung_pao_chicken.jpg",
                "veg": False
            },
            {
                "name": "Chicken Manchurian",
                "description": "Crispy chicken tossed in a spicy and tangy Manchurian sauce with spring onions.",
                "price": 250,
                "image": "/static/images/chicken_manchurian.webp",
                "veg": False
            },
            {
                "name": "Hakka Noodles",
                "description": "Stir-fried noodles with vegetables, garlic, and soy sauce for an authentic Chinese flavor.",
                "price": 220,
                "image": "/static/images/hakka_noodles.avif",
                "veg": True
            },
            {
                "name": "Spring Rolls",
                "description": "Crispy rolls stuffed with vegetables and served with a tangy dipping sauce.",
                "price": 150,
                "image": "/static/images/spring_rolls.jpg",
                "veg": True
            },
            {
                "name": "Dim Sums",
                "description": "Steamed dumplings with fillings such as chicken, prawns, or vegetables.",
                "price": 200,
                "image": "/static/images/dim_sums.jpg",
                "veg": True
            },
            {
                "name": "Hot and Sour Soup",
                "description": "A spicy and tangy soup with mushrooms, tofu, and bamboo shoots.",
                "price": 180,
                "image": "/static/images/hot_and_sour_soup.jpg",
                "veg": True
            }
        ]
    },
    {
        "id": "italian",
        "name": "Pasta Palace",
        "cuisine": "Italian",
        "description": "Classic Italian pasta, pizzas, and more.",
        "image": "/static/images/italian.jpg",
        "rating": 4.8,
        "menu": [
            {
                "name": "Margherita Pizza",
                "description": "Wood-fired pizza topped with tomato sauce, mozzarella, and fresh basil.",
                "price": 300,
                "image": "/static/images/margherita_pizza.jpg",
                "veg": True
            },
            {
                "name": "Spaghetti Bolognese",
                "description": "Classic Italian pasta dish with a rich meat sauce.",
                "price": 250,
                "image": "/static/images/spaghetti_bolognese.jpg",
                "veg": False
            },
            {
                "name": "Tiramisu",
                "description": "Classic Italian dessert made with coffee-soaked ladyfingers and mascarpone cream.",
                "price": 180,
                "image": "/static/images/tiramisu.jpg",
                "veg": True,

            },
            {
                "name": "Ravioli",
                "description": "Stuffed pasta with ricotta cheese and spinach, served with a tomato or cream sauce.",
                "price": 280,
                "image": "/static/images/ravioli.jpg",
                "veg": True
            },
            {
                "name": "Pasta Alfredo",
                "description": "Creamy Alfredo sauce tossed with fettuccine pasta and parmesan cheese.",
                "price": 280,
                "image": "/static/images/pasta_alfredo.jpg",
                "veg": False
            },
            {
                "name": "Garlic Bread",
                "description": "Toasted bread infused with garlic butter and fresh herbs.",
                "price": 130,
                "image": "/static/images/garlic_bread.jpg",
                "veg": True
            }
        ]
    },
    {
        "id": "north-indian",
        "name": "Royal Punjabi",
        "cuisine": "North Indian",
        "description": "Rich Punjabi flavors with delicious gravies and tandoori items.",
        "image": "/static/images/north-indian.jfif",
        "rating": 4.7,
        "menu": [
            {
                "name": "Butter Chicken",
                "description": "Tender chicken cooked in a creamy tomato-based gravy, served with naan.",
                "price": 350,
                "image": "/static/images/butter_chicken.jpg",
                "veg": False
            },
            {
                "name": "Tandoori Chicken",
                "description": "Marinated chicken cooked in a tandoor, served with mint chutney and naan.",
                "price": 300,
                "image": "/static/images/tandoori_chicken.jpg",
                "veg": False
            },
            {
                "name": "Paneer Butter Masala",
                "description": "Soft paneer cubes in a buttery, rich, and mildly spiced tomato gravy.",
                "price": 250,
                "image": "/static/images/paneer_butter_masala.jpg",
                "veg": True
            },
            {
                "name": "Dal Makhani",
                "description": "Slow-cooked black lentils in a creamy, buttery sauce.",
                "price": 200,
                "image": "/static/images/dal_makhani.jfif",
                "veg": True
            },
            {
                "name": "Aloo Gobi",
                "description": "A vegetarian dish made with potatoes, cauliflower, and Indian spices.",
                "price": 180,
                "image": "/static/images/aloo_gobi.jpg",
                "veg": True
            },
            {
                "name": "Chole Bhature",
                "description": "Spicy chickpea curry served with fried bread, a popular street food.",
                "price": 220,
                "image": "/static/images/chole_bhature.jpg",
                "veg": True
            }
        ]
    },
    {
        "id": "northeast-indian",
        "name": "NorthEast Flavors",
        "cuisine": "Northeast Indian",
        "description": "Aromatic dishes from Assam, Nagaland, Manipur, and Meghalaya.",
        "image": "/static/images/northeast.jpg",
        "rating": 4.6,
        "menu": [
            {
                "name": "Aloo Pitika",
                "description": "Mashed potatoes with mustard oil, onions, and green chilies.",
                "price": 150,
                "image": "/static/images/aloo_pitika.jpg",
                "veg": True
            },
            {
                "name": "Assam Laksa",
                "description": "A tangy and flavorful noodle soup with fish, tamarind, and lemongrass.",
                "price": 220,
                "image": "/static/images/assam_laksa.jpg",
                "veg": False
            },
            {
                "name": "Momos",
                "description": "Popular steamed dumplings, a beloved street food in the Northeast.",
                "price": 180,
                "image": "/static/images/momos.avif",
                "veg": True
            },
            {
                "name": "Thukpa",
                "description": "Tibetan noodle soup with vegetables and a flavorful broth.",
                "price": 200,
                "image": "/static/images/thukpa.png",
                "veg": True
            },
            {
                "name": "Fish Tenga",
                "description": "A quintessential Assamese fish dish, perfect for summer and winter meals.",
                "price": 250,
                "image": "/static/images/fish_tenga.jpg",
                "veg": False
            },
            {
                "name": "Eromba",
                "description": "A Manipuri dish made with boiled vegetables, fish, and fermented fish paste.",
                "price": 220,
                "image": "/static/images/eromba.jpg",
                "veg": False
            }
        ]
    },
    {
        "id": "odia",
        "name": "Odia Bhojana",
        "cuisine": "Odia Cuisine",
        "description": "Traditional Odia food prepared with love.",
        "image": "/static/images/odia.jpg",
        "rating": 4.9,
        "menu": [
            {
                "name": "Dalma",
                "description": "A wholesome dish of lentils and vegetables cooked with mustard seeds and ghee.",
                "price": 180,
                "image": "/static/images/dalma.jpg",
                "veg": True
            },
            {
                "name": "Chenna Jhili",
                "description": "A traditional Odia dessert made from cottage cheese, sugar, and ghee.",
                "price": 120,
                "image": "/static/images/chenna_jhili.jpg",
                "veg": True
            },
            {
                "name": "Chhena Poda",
                "description": "Caramelized cheese cake made from fresh chhena and jaggery.",
                "price": 150,
                "image": "/static/images/chhena_poda.jpg",
                "veg": True
            },
            {
                "name": "Kanika",
                "description": "A traditional dish of aromatic rice, lentils, and spices.",
                "price": 200,
                "image": "/static/images/kanika.jpg",
                "veg": True
            },
            {
                "name": "Pakhala Bhata",
                "description": "Fermented rice soaked in water, served with fried and mashed vegetables.",
                "price": 100,
                "image": "/static/images/pakhala.jpg",
                "veg": True
            },
            {
                "name": "Macha Besara",
                "description": "Fish curry made with mustard paste, garlic, and spices.",
                "price": 250,
                "image": "/static/images/macha_besara.jpg",
                "veg": False
            },
            {
                "name": "Chingudi Jhola",
                "description": "Prawn curry made with tomatoes, garlic, and spices.",
                "price": 280,
                "image": "/static/images/chingudi_jhola.jfif",
                "veg": False
            },
            {
                "name": "Badi Chura",
                "description": "A dry side dish made with fried lentil dumplings and spices.",
                "price": 120,
                "image": "/static/images/badi_chura.jpg",
                "veg": True
            },
            {
                "name": "Dahi Bara",
                "description": "Soft lentil dumplings soaked in spiced yogurt, garnished with chutneys.",
                "price": 80,
                "image": "/static/images/dahi_bara.jpeg",
                "veg": True
            },
            {
                "name": "Sandesh",
                "description": "A delicate Bengali sweet made from fresh paneer and subtly flavored with cardamom.",
                "price": 130,
                "image": "/static/images/sandesh.jpg",
                "veg": True     
            },
            {
                "name": "rasgulla",
                "description": "A traditional Odia dessert made from cottage cheese, sugar, and ghee.", 
                "price": 120, 
                "image": "/static/images/rasgulla.jfif",
                "veg": True
                }
        ]
    },
    {
        "id": "japanese",
        "name": "Sakura Bites",
        "cuisine": "Japanese",
        "description": "Authentic Japanese dishes with fresh ingredients.",
        "image": "/static/images/japanese.jpg",
        "rating": 4.8,
        "menu": [
            {
                "name": "Sushi",
                "description": "Vinegared rice with fresh fish or vegetables.",
                "price": 400,
                "image": "/static/images/sushi.jfif",
                "veg": False
            },
            {
                "name": "Ramen",
                "description": "Savory noodle soup with soy-based broth and tender meat.",
                "price": 350,
                "image": "/static/images/ramen.jfif",
                "veg": False
            },
            {
                "name": "Tempura",
                "description": "Crispy battered and fried seafood or vegetables with dipping sauce.",
                "price": 280,
                "image": "/static/images/tempura.jpg",
                "veg": False
            },
            {
                "name": "Udon",
                "description": "Thick wheat flour noodles served in a savory broth with toppings.",
                "price": 250,
                "image": "/static/images/udon.avif",
                "veg": True
            },
            {
                "name": "Yakitori",
                "description": "Grilled skewers of chicken, vegetables, or seafood.",
                "price": 200,
                "image": "/static/images/yakitori.jpg",
                "veg": False
            },
            {
                "name": "Miso Soup",
                "description": "Traditional Japanese soup made with miso paste, tofu, and seaweed.",
                "price": 150,
                "image": "/static/images/miso_soup.jpg",
                "veg": True
            }
        ]
    },
    {
        "id": "mediterranean-breeze",
        "name": "Mediterranean Breeze",
        "cuisine": "Mediterranean",
        "description": "Fresh and healthy Mediterranean dishes with a modern twist.",
        "image": "/static/images/mediterranean_breeze.jfif",
        "rating": 4.5,
        "menu": [
            {
                "name": "Greek Salad",
                "description": "Crisp lettuce, tomatoes, cucumbers, olives, and feta cheese dressed with olive oil.",
                "price": 220,
                "image": "/static/images/greek_salad.jpg",
                "veg": True
            },
            {
                "name": "Hummus Platter",
                "description": "Creamy chickpea hummus served with pita bread and fresh veggies.",
                "price": 180,
                "image": "/static/images/hummus_platter.jpg",
                "veg": True
            },
            {
                "name": "Falafel Wrap",
                "description": "Crispy falafel balls wrapped in a flatbread with tahini sauce and fresh vegetables.",
                "price": 200,
                "image": "/static/images/falafel_wrap.jpg",
                "veg": True
            },
            {
                "name": "Lamb Gyro",
                "description": "Slow-cooked lamb served in pita with tzatziki, tomatoes, and onions.",
                "price": 280,
                "image": "/static/images/lamb_gyro.jpg",
                "veg": False
            },
            {
                "name": "Spanakopita",
                "description": "Flaky phyllo pastry filled with spinach, feta cheese, and herbs.",
                "price": 190,
                "image": "/static/images/spanakopita.jpg",
                "veg": True
            },
            {
                "name": "Baklava",
                "description": "Sweet layers of phyllo pastry filled with chopped nuts and honey syrup.",
                "price": 150,
                "image": "/static/images/baklava.jpg",
                "veg": True
            }
        ]
    },
    {
        "id": "curry-corner",
        "name": "Curry Corner",
        "cuisine": "Fusion - Indian",
        "description": "A delightful fusion of Indian flavors in classic curries and sides.",
        "image": "/static/images/curry_corner.jfif",
        "rating": 4.6,
        "menu": [
            {
                "name": "Chicken Curry",
                "description": "Spicy and savory chicken curry simmered with onions, tomatoes, and a blend of Indian spices.",
                "price": 300,
                "image": "/static/images/chicken_curry.jpg",
                "veg": False
            },
            {
                "name": "Vegetable Korma",
                "description": "A rich and creamy curry made with mixed vegetables and aromatic spices.",
                "price": 220,
                "image": "/static/images/vegetable_korma.jpg",
                "veg": True
            },
            {
                "name": "Paneer Tikka Masala",
                "description": "Grilled paneer cubes in a luscious, spiced tomato gravy.",
                "price": 260,
                "image": "/static/images/paneer_tikka_masala.jpg",
                "veg": False
            },
            {
                "name": "Naan",
                "description": "Traditional oven-baked flatbread, perfect for scooping up curries.",
                "price": 80,
                "image": "/static/images/naan.jpg",
                "veg": True
            },
            {
                "name": "Rice Pilaf",
                "description": "Fragrant basmati rice cooked with aromatic spices and herbs.",
                "price": 150,
                "image": "/static/images/rice_pilaf.jpg",
                "veg": True
            }
        ]
    },
    {
        "id": "sushi-zen",
        "name": "Sushi Zen",
        "cuisine": "Japanese",
        "description": "An authentic Japanese dining experience offering the freshest sushi and more.",
        "image": "/static/images/sushi_zen.avif",
        "rating": 4.7,
        "menu": [
            {
                "name": "California Roll Sushi",
                "description": "Crab, avocado, and cucumber rolled in vinegared rice and seaweed.",
                "price": 320,
                "image": "/static/images/california_roll.jpg",
                "veg": False
            },
            {
                "name": "Spicy Tuna Roll",
                "description": "Fresh tuna mixed with spicy mayo rolled with rice and seaweed.",
                "price": 350,
                "image": "/static/images/spicy_tuna_roll.jfif",
                "veg": False

            },
            {
                "name": "Salmon Nigiri",
                "description": "Slices of fresh salmon over small beds of seasoned rice.",
                "price": 400,
                "image": "/static/images/salmon_nigiri.jpg",
                "veg": False
            },
            {
                "name": "Tempura Udon",
                "description": "Udon noodles in a savory broth, topped with crispy tempura shrimp.",
                "price": 380,
                "image": "/static/images/tempura_udon.jpg",
                "veg": False
            },
            {
                "name": "Miso Soup",
                "description": "Traditional Japanese soup made with miso paste, tofu, and seaweed.",
                "price": 180,
                "image": "/static/images/miso_soup2.jpg",
                "veg": True
            },
            {
                "name": "Green Tea Ice Cream",
                "description": "Smooth and creamy ice cream infused with authentic green tea flavor.",
                "price": 220,
                "image": "/static/images/green_tea_ice_cream.jpg",
                "veg": True
            }
        ]
    },
    {
        "id": "mexican-fiesta",
        "name": "Mexican Fiesta",
        "cuisine": "Mexican",
        "description": "Experience vibrant Mexican flavors with fresh ingredients and traditional recipes.",
        "image": "/static/images/mexican_fiesta.jpg",
        "rating": 4.6,
        "menu": [
            {"name": "Tacos al Pastor", "description": "Marinated pork tacos served with pineapple, cilantro, and onion.", "price": 150, "image": "/static/images/tacos_al_pastor.jpg", "veg": False},
            {"name": "Chicken Burrito", "description": "Flour tortilla stuffed with grilled chicken, beans, rice, and salsa.", "price": 200, "image": "/static/images/chicken_burrito.jpg", "veg": False},
            {"name": "Quesadillas", "description": "Grilled tortillas filled with melted cheese and your choice of meat or veggies.", "price": 180, "image": "/static/images/quesadillas.jfif", "veg": True},
            {"name": "Enchiladas", "description": "Corn tortillas rolled with filling and covered in a spicy enchilada sauce.", "price": 220, "image": "/static/images/enchiladas.jpg", "veg": False},
            {"name": "Nachos Supreme", "description": "Crispy tortilla chips loaded with cheese, jalapeños, guacamole, and sour cream.", "price": 170, "image": "/static/images/nachos_supreme.jfif", "veg": True},
            {"name": "Churros", "description": "Fried-dough pastry sprinkled with sugar and served with chocolate sauce.", "price": 120, "image": "/static/images/churros.jpg", "veg": True}
        ]
    },
    {
        "id": "thai-spice",
        "name": "Thai Spice",
        "cuisine": "Thai",
        "description": "Enjoy authentic Thai cuisine with aromatic spices, tangy flavors, and fresh herbs.",
        "image": "/static/images/thai_spice.jfif",
        "rating": 4.7,
        "menu": [
            {"name": "Pad Thai", "description": "Stir-fried rice noodles with tofu, shrimp, peanuts, and a tangy tamarind sauce.", "price": 250, "image": "/static/images/pad_thai.jpg", "veg": False},
            {"name": "Green Curry", "description": "A spicy and aromatic curry made with coconut milk, green chilies, and Thai basil.", "price": 280, "image": "/static/images/green_curry.jpg", "veg": True},
            {"name": "Tom Yum Soup", "description": "Hot and sour soup with shrimp, mushrooms, lemongrass, and kaffir lime leaves.", "price": 230, "image": "/static/images/tom_yum_soup.jpg", "veg": False},
            {"name": "Som Tum", "description": "Spicy green papaya salad tossed with lime, chili, and peanuts.", "price": 190, "image": "/static/images/som_tum.jpg","veg": True },
            {"name": "Massaman Curry", "description": "Mild, sweet curry with potatoes, peanuts, and your choice of meat.", "price": 300, "image": "/static/images/massaman_curry.jpg","veg": False},
            {"name": "Mango Sticky Rice", "description": "Sweet glutinous rice served with ripe mango slices and coconut milk.", "price": 200, "image": "/static/images/mango_sticky_rice.jfif","veg": True}
        ]
    },
    {
        "id": "fusion-delight",
        "name": "Fusion Delight",
        "cuisine": "Hybrid",
        "description": "A creative fusion of flavors combining elements of Chinese, Italian, and Indian cuisines.",
        "image": "/static/images/fusion_delight.webp",
        "rating": 4.8,
        "menu": [
            {"name": "Chow Mein Pizza", "description": "A unique twist on pizza topped with stir-fried noodles, veggies, and a light soy glaze.", "price": 350, "image": "/static/images/chow_mein_pizza.jfif", "veg": True},
            {"name": "Kung Pao Pasta", "description": "Spicy pasta tossed with bell peppers, peanuts, and a hint of Szechuan sauce.", "price": 320, "image": "/static/images/kung_pao_pasta.jpg", "veg": True},
            {"name": "Szechuan Risotto", "description": "Creamy risotto infused with Szechuan peppercorns and vibrant vegetables.", "price": 340, "image": "/static/images/szechuan_risotto.avif", "veg": True},
            {"name": "Chicken Roll", "description": "A fusion of Indian and Chinese flavors in a crispy fried chicken roll.", "price": 280, "image": "/static/images/chicken_roll.jpg", "veg": False},
            {"name": "Falafel Wrap", "description": "A crispy falafel patty wrapped in a soft tortilla with fresh veggies and hummus.", "price": 220, "image": "/static/images/falafel_wrap2.jpg", "veg": True},
            {"name": "Samosas", "description": "Crispy fried or baked pastries filled with spiced potatoes, peas.", "price": 150, "image": "/static/images/samosas.jpg", "veg": True},
            {"name": "Dim Sum Calzone", "description": "Calzone filled with classic dim sum ingredients and steamed to perfection.", "price": 370, "image": "/static/images/dim_sum_calzone.jpg", "veg": True},
            {"name": "Noodle Lasagna", "description": "Layers of noodles, cheese, and savory meat sauce with an Asian twist.", "price": 360, "image": "/static/images/noodle_lasagna.jfif", "veg": False},
            {"name": "Chicken Tikka", "description": "Tender chicken tikka served with garlic naan and a side of creamy pasta.", "price": 380, "image": "/static/images/chicken_tikka.jpg", "veg": False},
            {"name": " Egg Roll", "description": "A crispy fried roll filled with scrambled eggs, veggies, and a tangy sauce.", "price": 200, "image": "/static/images/egg_roll.png", "veg": False},
            {"name": "Tiramisu Spring Roll", "description": "A dessert fusion combining the flavors of Italian tiramisu wrapped in a crispy spring roll.", "price": 300, "image": "/static/images/tiramisu_spring_roll.jfif", "veg": True}
        ]
    },
    {
        "id": "bengali-bites",
        "name": "Bengali Bites",
        "cuisine": "Bengali",
        "description": "Savor the rich, diverse flavors of Bengal, from classic fish curries to delightful sweets.",
        "image": "/static/images/bengali_bites.jpg",
        "rating": 4.8,
        "menu": [
            {"name": "Shorshe Ilish", "description": "Hilsa fish cooked in a pungent mustard gravy, a quintessential Bengali delicacy.", "price": 350, "image": "/static/images/shorshe_ilish.jpg", "veg": False},
            {"name": "Kosha Mangsho", "description": "Slow-cooked spicy mutton curry rich in flavor and tradition.", "price": 400, "image": "/static/images/kosha_mangsho.webp", "veg": False},
            {"name": "Chingri Malai Curry", "description": "Succulent prawns simmered in a creamy coconut milk gravy with mild spices.", "price": 380, "image": "/static/images/chingri_malai_curry.avif", "veg": False},
            {"name": "Aloo Posto", "description": "Potatoes cooked in a poppy seed paste with subtle spices, a Bengali classic.", "price": 200, "image": "/static/images/aloo_posto.jfif", "veg": True},
            {"name": "Mishti Doi", "description": "Sweet, creamy yogurt dessert with a rich, caramelized flavor.", "price": 150, "image": "/static/images/mishti_doi.webp", "veg": True},
            {"name": "Sandesh", "description": "A delicate Bengali sweet made from fresh paneer and subtly flavored with cardamom.", "price": 130, "image": "/static/images/sandesh2.jpg", "veg": True},
        ]
    },
    # // Add more restaurants here...
]
posts = [
    {
        "id": 1,
        "title": "Best Paneer Butter Masala in Delhi?",
        "author": "Rahul Sharma",
        "body": "I've tried a few places in Delhi, but can't decide which one's best for paneer butter masala. Any recommendations?",
        "date_posted": "2025-05-07"
    },
    {
        "id": 2,
        "title": "Home-made Biryani Tips",
        "author": "Sneha Reddy",
        "body": "Tried making Hyderabadi biryani for the first time and it turned out dry. Any tips to get that juicy, layered flavour?",
        "date_posted": "2025-05-06"
    },
    {
        "id": 3,
        "title": "Street Food in Mumbai 😋",
        "author": "Amit Desai",
        "body": "Vada Pav and Misal Pav are unbeatable! Which vendor is your go-to in Mumbai for spicy treats?",
        "date_posted": "2025-05-05"
    },
    {
        "id": 4,
        "title": "Best Filter Coffee in Bangalore?",
        "author": "Priya Menon",
        "body": "Looking for a classic South Indian coffee experience. Filter coffee lovers, suggest your favourite cafés!",
        "date_posted": "2025-05-04"
    },
    {
        "id": 5,
        "title": "Chole Bhature in Chandigarh",
        "author": "Karanpreet Singh",
        "body": "Visited Gopal's and Sindhi Sweets. Who else serves fluffy bhature and spicy chole worth trying?",
        "date_posted": "2025-05-03"
    },
    {
        "id": 6,
        "title": "Idli Sambhar Lovers Unite!",
        "author": "Meera Iyer",
        "body": "Homemade or hotel-style? Share your sambhar secrets and how you make soft idlis!",
        "date_posted": "2025-05-02"
    }
]
# Sample preloaded order tracking data
   
# Function to load restaurant data
def load_restaurants():
    if os.path.exists(DATA_FILE):
        with open(DATA_FILE, "r") as f:
            return json.load(f)
    return default_restaurants

# Function to save restaurant data
def save_restaurants(data):
    with open(DATA_FILE, "w") as f:
        json.dump(data, f, indent=4)

# Home Page - Displays all restaurants with search
@app.route('/')
def index():
    query = request.args.get('q', '').strip().lower()
    food_type = request.args.get('food_type', '').strip().lower()
    veg_theme = (food_type == 'veg')

    all_restaurants = load_restaurants()

    # If filtering by food type (Veg/Non-Veg)
    if food_type in ['veg', 'nonveg']:
        food_items = []
        for restaurant in all_restaurants:
            for item in restaurant.get("menu", []):
                if (food_type == 'veg' and item.get("veg", False)) or (food_type == 'nonveg' and not item.get("veg", True)):
                    food_item = item.copy()
                    food_item["restaurant_name"] = restaurant["name"]
                    food_items.append(food_item)

        # Apply search filter
        if query:
            food_items = [f for f in food_items if query in f["name"].lower() or query in f["description"].lower()]

        return render_template('foods.html', food_items=food_items, query=query, veg_theme=veg_theme)

    # Filtering restaurants based on search query
    filtered_restaurants = [r for r in all_restaurants if query in r["name"].lower() or query in r["cuisine"].lower()] if query else all_restaurants
    return render_template('index.html', restaurants=filtered_restaurants, veg_theme=veg_theme)

# Restaurant Menu Page
@app.route('/restaurant/<restaurant_id>', endpoint='restaurant_menu')
def restaurant_menu(restaurant_id):
    restaurants = load_restaurants()
    selected_restaurant = next((r for r in restaurants if r["id"] == restaurant_id), None)
    if not selected_restaurant:
        return "Restaurant Not Found", 404
    return render_template('restaurant.html', restaurant=selected_restaurant)

# Foods Page - Aggregates all food items
@app.route('/foods')
def foods():
    query = request.args.get('q', '').strip().lower()
    restaurants = load_restaurants()
    food_items = []

    for restaurant in restaurants:
        for food in restaurant.get("menu", []):
            food_item = food.copy()
            food_item["restaurant_name"] = restaurant["name"]
            food_items.append(food_item)

    # Apply search filter
    if query:
        food_items = [f for f in food_items if query in f["name"].lower()]
    
    return render_template('foods.html', food_items=food_items, query=query)

# Veg Foods Page
@app.route('/veg')
def veg():
    all_restaurants = load_restaurants()
    veg_items = [
        {**item, "restaurant_name": restaurant["name"]}
        for restaurant in all_restaurants
        for item in restaurant.get("menu", []) if item.get("veg", False)
    ]
    return render_template('foods.html', food_items=veg_items, query="")

# Non-Veg Foods Page
@app.route('/nonveg')
def nonveg():
    all_restaurants = load_restaurants()
    nonveg_items = [
        {**item, "restaurant_name": restaurant["name"]}
        for restaurant in all_restaurants
        for item in restaurant.get("menu", []) if not item.get("veg", True)
    ]
    return render_template('foods.html', food_items=nonveg_items, query="")

# Store orders
orders = []

# Fetch Restaurant Menu
@app.route('/menu/<restaurant_id>')
def menu(restaurant_id):
    restaurants = load_restaurants()
    restaurant = next((r for r in restaurants if r["id"] == restaurant_id), None)
    if not restaurant:
        return "Restaurant Not Found", 404
    return render_template('menu.html', restaurant=restaurant)

# Filter Veg / Non-Veg Dishes
@app.route('/menu/filter')
def filter_menu():
    food_type = request.args.get('type')  # veg or nonveg
    restaurants = load_restaurants()
    filtered_dishes = [
        {"restaurant": r["name"], **dish}
        for r in restaurants
        for dish in r['menu']
        if (food_type == "veg" and dish["veg"]) or (food_type == "nonveg" and not dish["veg"])
    ]
    return jsonify(filtered_dishes)


# Reservation page
@app.route('/reserve', methods=['GET', 'POST'])
def reserve():
    if request.method == 'POST':
        name = request.form.get('name')
        date = request.form.get('date')
        time = request.form.get('time')
        guests = request.form.get('guests')
        phone = request.form.get('phone')
        return render_template('reserve.html', success=True, name=name, date=date, time=time, guests=guests, phone=phone)
    return render_template('reserve.html')

# Options page (if needed)
@app.route('/options', methods=['GET', 'POST'])
def options():
    if request.method == 'POST':
        # Process the submitted form data here
        restaurant_name = request.form.get('restaurant_name')
        theme = request.form.get('theme')
        currency = request.form.get('currency')
        notifications = request.form.get('notifications') == 'on'

        # For now, just display a success message
        return render_template('options.html', success=True, restaurant_name=restaurant_name)

    return render_template('options.html')


# Forum page (if needed)
@app.route('/forum')
def forum():
    return render_template('forum.html', posts=posts)

@app.route('/post/<int:post_id>')
def view_post(post_id):
    post = next((post for post in posts if post['id'] == post_id), None)
    if not post:
        return "Post not found", 404
    return render_template('view_post.html', post=post)


@app.route('/order', methods=['GET', 'POST'])
def order():
    if request.method == 'POST':
        name = request.form['name']
        food = request.form['food']
        restaurant = request.form['restaurant']
        price = float(request.form['price'])  # make sure this is float
        quantity = int(request.form['quantity'])
        address = request.form['address']
        total_price = price * quantity

        # You can save to DB here if needed

        return render_template(
            'order_success.html',
            name=name,
            food=food,
            restaurant=restaurant,
            quantity=quantity,
            total_price=total_price,
            address=address
        )

    food = request.args.get('food', '')
    restaurant = request.args.get('restaurant', '')
    price = request.args.get('price', '')
    return render_template('order.html', food=food, restaurant=restaurant, price=price)

@app.route('/order/menu')
def order_menu():
    available_items = []
    for restaurant in default_restaurants:
        for item in restaurant['menu']:
            item_data = item.copy()
            item_data['restaurant_name'] = restaurant['name']
            available_items.append(item_data)

    return render_template('order_menu.html', menu_items=available_items)


if __name__ == '__main__':
    app.run(debug=True)
