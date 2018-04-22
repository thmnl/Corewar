.name "caca"
.comment "Darty papa"

      sti r1,%:code,%1
      ld %0,r3
code: live %1
      zjmp %:code
