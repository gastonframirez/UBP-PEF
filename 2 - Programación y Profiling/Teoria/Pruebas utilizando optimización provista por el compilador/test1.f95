PROGRAM SumaReales1

  IMPLICIT NONE

  REAL :: X=0.1, Y=1.0, RESULTADOR=0.0
  DOUBLE PRECISION :: XX=0.1, YY=1.0, RESULTADOD=0.0
  INTEGER :: I

  DO I=1,10
    X  = X  * 0.1
    XX = XX * 0.1
    Y  = Y  * 10.0
    YY = YY * 10.0

    RESULTADOR = X  + Y;
    RESULTADOD = XX + YY;

    WRITE (*,*) 'Utilizando REAL:   ', X, ' + ', Y, ' = ', RESULTADOR
    WRITE (*,*) 'Utilizando DOUBLE: ', XX,' + ',YY, ' = ', RESULTADOD
    WRITE (*,*) ' '
  ENDDO

END PROGRAM SumaReales1
