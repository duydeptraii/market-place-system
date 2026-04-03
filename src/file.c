/*
 * file.c
 *
 * Description:
 * This file handles all file input and output operations for the system.
 * It reads data from files into linked lists and writes updated data
 * back to files.
 *
 * Responsibilities:
 * - Load game data from file into linked list
 * - Save game data to file
 * - Save and load purchase history
 * - Ensure data persistence between program runs
 *
 * Files Used:
 * - data/games.txt
 * - data/history.txt
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>