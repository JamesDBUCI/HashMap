// HashMapTests.cpp
//
// ICS 45C Fall 2014
// Project #3: Maps and Legends
//
// Write unit tests for your HashMap class here.  I've provided one test already,
// though I've commented it out, because it won't compile until you've implemented
// three things: the HashMap constructor, the HashMap destructor, and HashMap's
// size() member function.

#include <gtest/gtest.h>
#include "HashMap.hpp"


TEST(TestHashMap, sizeOfNewlyCreatedHashMapIsZero)
{
   HashMap empty;
   ASSERT_EQ(0, empty.size());
}

TEST(TestHashMap, testAdd)
{
   HashMap hm1;
   std::string key{"Boo"};
   std::string value{"perfect"};
   hm1.add(key, value);
   ASSERT_EQ("perfect", hm1.value("Boo"));

   hm1.remove("Boo");
   ASSERT_EQ(false, hm1.contains("Boo"));
   hm1.add(key, value);
   ASSERT_EQ(true, hm1.contains("Boo"));

}

TEST(TestHashMap, testRemove)
{
   HashMap hm1;
   std::string key{"Boo"};
   std::string value{"perfect"};
   hm1.add(key, value);
   ASSERT_EQ("perfect", hm1.value("Boo"));

   hm1.remove("Boo");
   ASSERT_EQ(false, hm1.contains("Boo"));

}

TEST(TestHashMap, testSize)
{
   HashMap hm1;
   std::string key{"Boo"};
   std::string value{"perfect"};
   hm1.add(key, value);
   ASSERT_EQ("perfect", hm1.value("Boo"));

   hm1.remove("Boo");
   ASSERT_EQ(false, hm1.contains("Boo"));
   hm1.add(key, value);
   ASSERT_EQ(true, hm1.contains("Boo"));


   ASSERT_EQ(1, hm1.size());
   ASSERT_EQ(10, hm1.bucketCount());
   hm1.add("Trung0", "Nguyen0");
   ASSERT_EQ(2, hm1.size());

   hm1.add("Trung1", "Nguyen1");
   hm1.add("Trung2", "Nguyen2");
   hm1.add("Trung3", "Nguyen3");
   hm1.add("Trung4", "Nguyen4");
   hm1.add("Trung5", "Nguyen5");
   hm1.add("Trung6", "Nguyen6");
   ASSERT_EQ(8, hm1.size());
   ASSERT_EQ(0.8, hm1.loadFactor());
   ASSERT_EQ(10, hm1.bucketCount());
   hm1.add("Trung7", "Nguyen7");
   ASSERT_EQ(9, hm1.size());

}

TEST(TestHashMap, testBucketCount)
{
   HashMap hm1;
   std::string key{"Boo"};
   std::string value{"perfect"};
   hm1.add(key, value);
   ASSERT_EQ("perfect", hm1.value("Boo"));

   hm1.remove("Boo");
   ASSERT_EQ(false, hm1.contains("Boo"));
   hm1.add(key, value);
   ASSERT_EQ(true, hm1.contains("Boo"));


   ASSERT_EQ(1, hm1.size());
   ASSERT_EQ(10, hm1.bucketCount());
   hm1.add("Trung0", "Nguyen0");
   ASSERT_EQ(2, hm1.size());

   hm1.add("Trung1", "Nguyen1");
   hm1.add("Trung2", "Nguyen2");
   hm1.add("Trung3", "Nguyen3");
   hm1.add("Trung4", "Nguyen4");
   hm1.add("Trung5", "Nguyen5");
   hm1.add("Trung6", "Nguyen6");
   ASSERT_EQ(8, hm1.size());
   ASSERT_EQ(0.8, hm1.loadFactor());
   ASSERT_EQ(10, hm1.bucketCount());
   hm1.add("Trung7", "Nguyen7");
   ASSERT_EQ(9, hm1.size());
   ASSERT_NEAR(0.428, hm1.loadFactor(), 0.001);
   ASSERT_EQ(21, hm1.bucketCount());
   
}

TEST(TestHashMap, testCopy)
{
   HashMap hm1;
   std::string key{"Boo"};
   std::string value{"perfect"};
   hm1.add(key, value);
   ASSERT_EQ("perfect", hm1.value("Boo"));

   hm1.remove("Boo");
   ASSERT_EQ(false, hm1.contains("Boo"));
   hm1.add(key, value);
   ASSERT_EQ(true, hm1.contains("Boo"));


   ASSERT_EQ(1, hm1.size());
   ASSERT_EQ(10, hm1.bucketCount());
   hm1.add("Trung0", "Nguyen0");
   ASSERT_EQ(2, hm1.size());

   hm1.add("Trung1", "Nguyen1");
   hm1.add("Trung2", "Nguyen2");
   hm1.add("Trung3", "Nguyen3");
   hm1.add("Trung4", "Nguyen4");
   hm1.add("Trung5", "Nguyen5");
   hm1.add("Trung6", "Nguyen6");
   ASSERT_EQ(8, hm1.size());
   ASSERT_EQ(0.8, hm1.loadFactor());
   ASSERT_EQ(10, hm1.bucketCount());
   hm1.add("Trung7", "Nguyen7");
   ASSERT_EQ(9, hm1.size());
   ASSERT_NEAR(0.428, hm1.loadFactor(), 0.001);
   ASSERT_EQ(21, hm1.bucketCount());
   

   ASSERT_EQ(true, hm1.contains("Boo"));
   hm1.remove("Trung7");
   ASSERT_EQ(false, hm1.contains("Trung7"));

   hm1.remove("Trung7");
   hm1.remove("Trung6");
   hm1.remove("Trung5");
   hm1.remove("Trung4");
   ASSERT_EQ(5, hm1.size());
   ASSERT_EQ(21, hm1.bucketCount());

   HashMap hm2{hm1};
   ASSERT_EQ(5, hm2.size());
   ASSERT_EQ(true, hm2.contains("Trung3"));
   ASSERT_EQ(false, hm2.contains("Trung4"));

}

TEST(TestHashMap, testLoadFactor)
{
   HashMap hm1;
   std::string key{"Boo"};
   std::string value{"perfect"};
   hm1.add(key, value);
   ASSERT_EQ("perfect", hm1.value("Boo"));

   hm1.remove("Boo");
   ASSERT_EQ(false, hm1.contains("Boo"));
   hm1.add(key, value);
   ASSERT_EQ(true, hm1.contains("Boo"));


   ASSERT_EQ(1, hm1.size());
   ASSERT_EQ(10, hm1.bucketCount());
   hm1.add("Trung0", "Nguyen0");
   ASSERT_EQ(2, hm1.size());

   hm1.add("Trung1", "Nguyen1");
   hm1.add("Trung2", "Nguyen2");
   hm1.add("Trung3", "Nguyen3");
   hm1.add("Trung4", "Nguyen4");
   hm1.add("Trung5", "Nguyen5");
   hm1.add("Trung6", "Nguyen6");
   ASSERT_EQ(8, hm1.size());
   ASSERT_EQ(0.8, hm1.loadFactor());
   ASSERT_EQ(10, hm1.bucketCount());
   hm1.add("Trung7", "Nguyen7");
   ASSERT_EQ(9, hm1.size());
   ASSERT_NEAR(0.428, hm1.loadFactor(), 0.001);
}

TEST(TestHashMap, testDeepCopy)
{

   HashMap hm1;
      std::string key{"Boo"};
      std::string value{"perfect"};
      hm1.add(key, value);
      hm1.add("Trung0", "Nguyen0");
      hm1.add("Trung1", "Nguyen1");
      hm1.add("Trung2", "Nguyen2");
      hm1.add("Trung3", "Nguyen3");
      hm1.add("Trung4", "Nguyen4");
      hm1.add("Trung5", "Nguyen5");
      hm1.add("Trung6", "Nguyen6");
      hm1.add("Trung7", "Nguyen7");


      
      HashMap hm2 = hm1;
      
      ASSERT_EQ(true, hm2.contains("Boo"));
      ASSERT_EQ(true, hm2.contains("Trung0"));
      ASSERT_EQ(true, hm2.contains("Trung1"));
      ASSERT_EQ(true, hm2.contains("Trung2"));
      ASSERT_EQ(true, hm2.contains("Trung3"));
      ASSERT_EQ(true, hm2.contains("Trung4"));
      ASSERT_EQ(true, hm2.contains("Trung5"));
      ASSERT_EQ(true, hm2.contains("Trung6"));
      ASSERT_EQ(true, hm2.contains("Trung7"));
}