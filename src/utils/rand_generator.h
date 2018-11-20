#ifndef __RAND_GENERATOR_H__
#define __RAND_GENERATOR_H__

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class rand_generator
{
public:
    rand_generator()
    {
        m_source_sequences_of_characters = "abcdefghigklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
        m_source_sequences_of_characters_length = strlen(m_source_sequences_of_characters);

        srand((unsigned)time(NULL));
    }

    void get_rand_string(char* dst_string, int dst_string_length)
    {
        for (int i = 0; i < dst_string_length; i++)
        {
            dst_string[i] = m_source_sequences_of_characters[rand() % m_source_sequences_of_characters_length];
        }
    }

private:
    char* m_source_sequences_of_characters;
    int m_source_sequences_of_characters_length;
};

#endif