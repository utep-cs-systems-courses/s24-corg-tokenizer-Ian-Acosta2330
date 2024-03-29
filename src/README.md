Project 1: Tokenizer
====================
# Instructions:

You should document your tokenizer in this file.

This file is written in the refreshingly simple `markdown` text
formatting language.

To learn about text formatting using markdown, we encourage you to examine 
 - [../README.md](../README.md)
 - the online [Markdown Guide](https://www.markdownguide.org/).

## **Overview**
The tokenizer project should be able to receive a string from the user
and separate via whitespaces.

## Methods for tokenizer.c

### space_char

Used to detect if a character is a space, if yes returns 1, if not returns 0

### non_space_char

Detects the exact opposite with opposite tests from the space_char method.

### token_start

Keeps moving up a string until it finds a whitespace, then returns the
position of the first non-space char

### token_terminator

Once in a word, there is an incrementer that indicates and returns first
white-space character.

### count_tokens

Counts the number of separate words/tokens in the given string

### copy_str

Returns contents of provided char string and terminates with null symbol

### tokenize

The delimiter of our program. Utilizes other methods to separate tokens by
whitespaces.

### print_tokens

Prints all the tokens of the char pointer-to-pointer

### free_tokens

Frees the allocated memory tokens

## Methods for history.c

## init_history

Initializes an empty List with the root pointing to NULL

## add_history

Used to append an item to the linked list. Utilizes variable 'tempItem" to
store new information to be added. 'temp' variable is meant to avoid moving
the actual list along, serves as a copy of whats currently in the list.

## get_history

Retrieves specific node from user specified id. Otherwise, just returns n/a.

## print_history

Prints the entire linked list with the ID and its corresponding string.

## free_history

Frees up the space that was allocated with each Item in the linked list as
well as the list itself. 
