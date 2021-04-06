<h1 class="gap">0x1F. Pascal's Triangle</h1>

<div data-role="task3772" data-position="15" id="task-num-0">
        <div class="panel panel-default task-card " id="task-3772">
  <span id="user_id" data-id="1237"></span>

  <div class="panel-heading">
    <h3 class="panel-title">
      0. Pascal's Triangle
    </h3>

    <div>
        <span class="label label-warning">
          mandatory
        </span>
    </div>
  </div>

  <div class="panel-body">
    <span id="user_id" data-id="1237"></span>

    

    <!-- Progress vs Score -->

    <!-- Task Body -->
    <p>Create a function <code>def pascal_triangle(n):</code> that returns a list of lists of integers representing the Pascal’s triangle of <code>n</code>:</p>

<ul>
<li>Returns an empty list if <code>n &lt;= 0</code></li>
<li>You can assume <code>n</code> will be always an integer</li>
</ul>

<pre><code>guillaume@ubuntu:~/0x1F$ cat 0-main.py
#!/usr/bin/python3
"""
0-main
"""
pascal_triangle = __import__('0-pascal_triangle').pascal_triangle

def print_triangle(triangle):
    """
    Print the triangle
    """
    for row in triangle:
        print("[{}]".format(",".join([str(x) for x in row])))


if __name__ == "__main__":
    print_triangle(pascal_triangle(5))

guillaume@ubuntu:~/0x1F$ 
guillaume@ubuntu:~/0x1F$ ./0-main.py
[1]
[1,1]
[1,2,1]
[1,3,3,1]
[1,4,6,4,1]
guillaume@ubuntu:~/0x1F$ 
</code></pre>



