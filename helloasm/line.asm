    org 32768
    ; load the screen memory address
    ld de,16384
    ; draw 8 pixels
    ld a, 255
    ld (de), a
    main:  
      jr main      ;loop forever!   
    end 32768
