+---------------------------+
|      Start updateBook()   |
+------------+--------------+
             |
             v
+---------------------------+
|   Check if user logged in |
|   (current_user_id != -1) |
+------------+--------------+
             |
    +--------+---------+
    |                  |
    v                  v
+----------+    +--------------+
| Not       |    | Logged in   |
| logged in |    |             |
+----+------+    +------+------+
     |                  |
     v                  v
+----------+    +--------------+
| Show error|    | Check if     |
| message   |    | library has  |
| & return  |    | books        |
+----------+    +------+-------+
                       |
              +--------+--------+
              |                 |
              v                 v
      +--------------+  +---------------+
      | Library empty|  | Library has   |
      | Show message |  | books         |
      | & return     |  |               |
      +--------------+  +-------+-------+
                                |
                                v
                       +----------------+
                       | Enter Book ID  |
                       | to update      |
                       +-------+--------+
                               |
                +------+-------+------+
                |      |              |
                v      v              v
        +----------+ +----------+ +----------+
        | ID = 0   | | ID < 0   | | ID > 0   |
        | Cancel   | | Invalid  | | Continue |
        | & return | | ID       | |          |
        +----------+ +----+-----+ +----+-----+
                          |            |
                          |            v
                          |     +----------------+
                          |     | Find book by   |
                          |     | ID in library  |
                          |     +-------+--------+
                          |             |
                          |    +--------+-------+
                          |    |                |
                          |    v                v
                          | +----------+  +----------+
                          | | Book not |  | Book     |
                          | | found    |  | found    |
                          | +----+-----+  +----+-----+
                          |      |             |
                          +------+             v
                                        +----------------+
                                        | Display current|
                                        | book details   |
                                        +-------+--------+
                                                |
                                                v
                                        +----------------+
                                        | Show update    |
                                        | field options  |
                                        | (1-8, 0=finish)|
                                        +-------+--------+
                                                |
                                                v
                                        +----------------+
                                        | Get field      |
                                        | to update      |
                                        +-------+--------+
                                                |
                                  +-------------+-------------+
                                  |             |             |
                                  v             v             v
                          +----------+  +------------+  +----------+
                          | Field = 0|  | Field = 1  |  | Field 2-8|
                          | Finish   |  | Cannot     |  | Update   |
                          | update   |  | update ID  |  | field    |
                          +----+-----+  +-----+------+  +----+-----+
                               |              |              |
                               |              |              v
                               |              |       +----------------+
                               |              |       | Enter new value|
                               |              |       | for field      |
                               |              |       +-------+--------+
                               |              |               |
                               |              |       +-------+--------+
                               |              |       | Validate       |
                               |              |       | new value      |
                               |              |       +-------+--------+
                               |              |               |
                               |              |      +--------+--------+
                               |              |      |                 |
                               |              |      v                 v
                               |              | +----------+    +----------+
                               |              | | Invalid  |    | Valid    |
                               |              | | value    |    | value    |
                               |              | | Show     |    | Update   |
                               |              | | error    |    | field    |
                               |              | +----------+    +----------+
                               |              |                       |
                               |              +-----------------------+
                               |                                      |
                               |                                      v
                               |                               +----------------+
                               |                               | Show update    |
                               |                               | field options  |
                               |                               | again          |
                               |                               +-------+--------+
                               |                                       |
                               |                                       |
                               |                                       |
                               |                                       |
                               v                                       |
                       +----------------+                              |
                       | Show progress  |                              |
                       | bar            |                              |
                       +-------+--------+                              |
                               |                                       |
                               v                                       |
                       +----------------+                              |
                       | Show success   |<-----------------------------+
                       | message        |
                       +-------+--------+
                               |
                               v
                       +----------------+
                       |     Return     |
                       +----------------+