PROGRAM FloatingPoint1

  IMPLICIT NONE

  REAL    :: X=0.0, Y, Z
  DOUBLE PRECISION :: XX=0.0,YY,ZZ
  INTEGER :: I, ACC=0

  PRINT *,'Ejecutando para REAL'
  DO I=1, 1000
    X = X + 1.0
    Y = 1.0 / X
    Z = Y * X
    IF ( Z /= 1.0 ) THEN
      ACC = ACC + 1
    ENDIF
  ENDDO

  PRINT *,'Se acertaron ', ACC ,' veces'

  PRINT *,'Ejecutando para DOUBLE'
  DO I=1, 1000
    XX = XX + 1.0
    YY = 1.0 / XX
    ZZ = YY * XX
    IF ( ZZ /= 1.0 ) THEN
      ACC = ACC + 1
    ENDIF
  ENDDO

  PRINT *,'Se acertaron ', ACC ,' veces'

END PROGRAM FloatingPoint1
