<h1># Note manager in C</h1>

This is a simple command-line Note manager written in C Programming Language.

It allows users to create, view,  and delete personal notes stored in  a text file.

<h2>## Features ##</h2>
-- Add new notes<br>
-- Display all saved notes<br>
-- Delete a note by its ID<br>
-- Notes are saved with timestapms<br>

<h2>## How it works ##</h2>

Each note is stored in atext file using this format:<br>
<h5>id|title|content|created_time</h5>

<h2>-- How to compile and run --</h2>
<h3>Requirements</h3>
GCC or compatible C  compiler
Linux or UNIX-line system

<h3>How to compile</h3>
bash<br>
gcc main.c utils/note_io.c -o note_manager<br>
<h3>How to Run</h3>
bash<br>
./note_manager

<h2>License</h2>
This project is open-source and free to use
