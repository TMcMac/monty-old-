+++++ +++++         #Set incrementer to 10 for 10 runs        
[                      
    > +++++ ++      #H is 72 so this is 70
    > +++++ +++++ + #o is 111 so this is 110
    > +++++ +++++ + #l is 108 so this is 110
    > +++++ +++++   #b is 98 so this 100
    > +++++ +++++   #e is 101 so this is 110
    > +++++ +++++ + #r is 114 so this is 110
    > +++++ +++++ + #t is 116 so this is 110
    > +++++ +++++ + #o is 111 so this is 110
    > +++++ +++++ + #n is 110 and this is 110
    <<<<<<<<< -
]
> ++ .              # adds 2 for 72 prints H
> + .               # adds 1 for 111 prints o
> -- .              # subs 2 for 108 prints l  
> -- .              # subs 2 for 98 prints b
> + .               # adds 1 for 101 prints e
> ++++ .            # adds 4 for 114 prints r
> ++++++ .          # adds 6 for 116 prints t
> + .               # adds 1 for 111 prints o   
> .                 # prints n
>++++++++++ .       # prints newline