A simple tool to convert between dBFS and floating point values:

    ]$ ./dbfloat -h
    Usage:

      dbfloat FLOAT | FLOAT%
        Convert float number or percent value to dBFS value.

      dbfloat FLOATdb
        Convert dBFS value to float number and percent value.

    ]$ ./dbfloat 0.5
    -6.02 dBFS ( -6.0205999 )

    ]$ ./dbfloat 150%
    3.52 dBFS ( 3.5218252 )

    ]$ ./dbfloat -40db
    0.01000000 ( 1.00% )



