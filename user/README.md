+---------------+     +----------------+     +-------------------+
| System Startup|---->| Check auto-login|---->| Branch by status  |
| (Load data)   |     | lastlogin.txt   |     +--------+----------+
+---------------+     +----------------+              |
                                                      |
 +--------------------------------------------------+ |
 |                                                  | |
 v                                                  v v
+---------------+     +---------------+     +----------------+
| User Menu     |     | Login Process |     | Auto-login OK  |
| 1. Register   |<-+  | - Enter ID    |---->| current_user_id|
| 2. Login      |--+->| - Enter pwd   |     | > 0            |
| 0. Exit       |  |  +-------+-------+     +--------+-------+
+---------------+  |          |                      |
       ^           |          v                      |
       |           |  +----------------+             |
+------+--------+  |  | Verify creds   |             |
| Register      |  |  +-------+--------+             |
| - Enter ID    |  |          |                      |
| - Enter name  |  |   +------+---------+            |
| - Enter pwd   |  |   |                |            |
+------+--------+  |   v                v            |
       |           | +--------+    +------------+    |
       v           | | Failed |    | Success    |    |
+---------------+  | | Show   |    | Set user_id|    |
| Validate:     |  | | error  |    | Save login |    |
| - ID unique?  |  | +--------+    +------+-----+    |
| - Name valid? |  |                      |          |
| - Pwd valid?  |  |                      |          |
+------+--------+  |                      |          |
       |           |                      v          v
       v           |               +----------------+-----------------+
+---------------+  |               | Main App Menu                    |
| Save user     |  |               | 1-8. Library functions           |
| - users array |  |               | 9. Logout                        |
| - users.txt   |--+               | 0. Exit                          |
+---------------+                  +----------------+-----------------+
                                                    |
                                                    v
                                   +----------------+-----------------+
                                   | Logout                           |
                                   | - Set current_user_id = -1       |
                                   | - Delete lastlogin.txt           |
                                   +------------------------------------+
                                                    |
                                                    v
                                                 (Return to
                                                  User Menu)