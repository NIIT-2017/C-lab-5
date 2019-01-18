#include "task1.h"
#include "task3.h"

#include "gtest/gtest.h"

TEST(task1, random_words)
{
   char in[256]={"my flat is not very big"};
   char out[256];
   randomWords(in,out);

   ASSERT_STRNE(in, out);
}

TEST(task3, mix_chars)
{
   char in1[256]="mad max";
   char out1[256];
   char in2[256]="hello world";
   char out2[256];
   mixLine(in1,out1);
   ASSERT_STREQ(in1,out1);
   mixLine(in2,out2);
   ASSERT_STRNE(in2,out2);
}