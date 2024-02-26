# Yap is a functional programming language that begrudgingly can become procedural

# comments start with a percent

# function definitions are surrounded by parentheses
(main argc:int, argv:char<vec>)
{
    x:int = 0;
    y:int = (inc x);

    # similarly to Rust, one can implicitly return a value by placing it by
    # itself on the last line of a function
    y;
}

# Strings are quoted
(println "Hello, world");
