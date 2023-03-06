
# lem-in

Lem-in is a project made at Hive Helsinki School of 42 network. It involves finding the shortest path through a graph of connected rooms. The project involves implementing a graph data structure, performing graph traversal, and finding the shortest path using an algorithm such as Dijkstra's algorithm.

## Usage
To run the lem-in program, simply run the executable with a map file as an argument:

``
./lem-in < map_file
``
The map file should be formatted as follows:
* The first line should be the number of ants that need to traverse the graph.
* The second line should be the starting room.
* The third line should be the ending room.
* Each subsequent line should describe a room in the graph, formatted as follows:
``
room_name x y
`` where room_name is the name of the room, and x and y are its coordinates in 2D space.

* After the list of rooms, there should be a list of connections between rooms, one connection per line. Each connection should be formatted as follows:
``
room_name_1-room_name_2`` where room_name_1 and room_name_2 are the names of the two rooms being connected.

Here's an example map file:

```
5
start
end
room1 1 2
room2 2 2
room3 3 2
start-room1
room1-room2
room2-room3
room3-end
```
## Output
The lem-in program will output the following information:

* The map file, followed by an empty line.
* The number of ants that need to traverse the graph, followed by an empty line.
* The shortest path from the starting room to the ending room, followed by an empty line.
* The list of ant movements needed to traverse the graph. Each line should contain the ant's ID and the name of the room it's moving to, separated by a dash. For example:
```
L1-room1
L2-room1
L1-end
```
This indicates that ant 1 moves to room1, ant 2 also moves to room1, and then ant 1 moves to the end room.

## License
The lem-in project is licensed under the MIT License. See the LICENSE file for details.
