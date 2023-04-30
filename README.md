[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10815389&assignment_repo_type=AssignmentRepo)
# Project-CS180 Team-L

# IMDB Datastore

## Project Description

The system will consist of a database of movies and TV shows. In addition to the movie title and rating, the database will include the cast, genre, as well as director. The database will be managed through a front-end GUI, where CRUD operations can be executed. CRUD operations can also be performed in the command line as well.

## Team Members

- Brian Porter
- Nicky Lin
- Johnny To
- Ryan
- Ian

## Objectives

- Create a database from scratch that is able to do basic CRUD Operations.
- Create a frontend GUI where developers can manage database.
- Create a CLI where developers can manage database.
- Create REST API's to allow the backend and frontend to interact with eachother.

## Technologies Used

- C++ for the database
- Javascript (Electron.js) HTML, CSS
- REST API tools TBD

## Interface Documentation

```text
  +-----------------+
  |    MovieDB      |
  +-----------------+
  | -movies: vector<Movie> |
  +-----------------+
  | +add_movie(movie: Movie) |
  | +get_movie(name: string): Movie* |
  | +update_movie(name: string, movie: Movie) |
  | +delete_movie(name: string) |
  | +save_to_file(filename: string) |
  | +load_from_file(filename: string) |
  +-----------------+

        ^
        |
        |
  +-----------------+
  |      Movie      |
  +-----------------+
  | -name: string   |
  | -director: string |
  | -actors: vector<string> |
  | -year_released: int |
  | -genre: string |
  +-----------------+
  | +Movie(name: string, director: string, actors: vector<string>, year_released: int, genre: string) |
  | +get_name(): string |
  | +get_director(): string |
  | +get_actors(): vector<string> |
  | +get_year_released(): int |
  | +get_genre(): string |
  | +set_name(name: string) |
  | +set_director(director: string) |
  | +set_actors(actors: vector<string>) |
  | +set_year_released(year_released: int) |
  | +set_genre(genre: string) |
  +-----------------+

```
- Create new entries within the database (Creates a new movie object and calls the functions to enter the movie details)
- Edit entries in the database (Calls the appropriate set functions correlated with the field you want to update)
- Delete entries in the database (call the delete movie function)
- Read entries in the database (Call the read movie function)
- CRUD Operations will be accessible through a command line interface (or a Web GUI if time permits)

## Critical Path/Milestones

| Sprint 1 | Sprint 2 | Sprint 3 | Sprint 4 |
| --- | --- | --- | --- |
| Initial Design Documentation | Add CRUD Functions | Sprint 3 Milestone 1  | Sprint 4 Milestone 1 |
| Research database implementation | Create Movie Object w/ Fields | Sprint 3 Milestone 2  | Sprint 4 Milestone 2 |
| Update Readme | Research C++ to JSON File | Sprint 3 Milestone 3 | Sprint 4 Milestone 3 |

## Burndown Chart

![Burndown Chart](https://user-images.githubusercontent.com/54635679/230989059-ec5c78e0-11c2-4d55-83b4-6b523d3247e4.png)
)

## Starting the GUI
to start the GUI
```
cd GUI
yarn start
```
to quit is the same as a Node.js enviroment: (Ctrl + C).
If you want to edit the code in the gui, please refer to the README.md in the gui folder.


