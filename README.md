

This project demonstrates the use of a B+ Tree indexing structure for efficient product price range searches in a large e-commerce catalog similar to Flipkart.

The case study analyzes:

* B+ Tree query cost
* Range query optimization
* Bug identification and correction
* Comparison with secondary hash indexing

---



Flipkart's product catalog contains millions of products organized by category and price.

The majority of user queries involve searching products within a specific price range.

Example:

Price Range: ₹1000 – ₹5000

The goal is to efficiently count and retrieve matching products using a B+ Tree.

---



* Product price insertion
* Range query search
* Product count within a price range
* Efficient leaf-node traversal
* Demonstration of B+ Tree indexing

---



* C++
* Data Structures
* B+ Tree Concepts

---





```bash
g++ main.cpp -o flipkart
flipkart
```



```bash
g++ main.cpp -o flipkart
./flipkart
```

---



```text
Product Prices:
500 700 1000 1200 1500 2000 2500 3000 3500 4000 4500 5000 5500 6000

Range Query: 1000 to 5000
Matching Products = 10
```

---



Given:

* Products = 10,000,000
* Leaf Capacity = 200
* Fanout = 128

Calculated:

* Leaf Pages = 50,000
* Tree Height ≈ 4 levels

For a result set of 2,500 products:

* Leaf Pages Scanned ≈ 13
* Total Page Reads ≈ 17

---



B+ Trees are highly efficient for range queries because leaf nodes are linked together, allowing sequential traversal. Compared with hash indexing, B+ Trees are the preferred choice when the workload consists mainly of price-range searches.
