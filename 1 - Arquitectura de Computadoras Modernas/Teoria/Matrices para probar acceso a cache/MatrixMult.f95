!
! Autor: Maximiliano A. Eschoyez
!
! Wed Aug 22 12:05:19 ART 2007
!

PROGRAM MATRIXMULT

  IMPLICIT NONE

  INTEGER :: I,J,K,N,M
!  PARAMETER (N=10, M=10)
  PARAMETER (N=1000, M=1000)
  REAL :: A(M,N), B(M,N), C(M,N), SUM

  DO I=1,M
    DO J=1,N
      A(I,J) = 2.0
      B(I,J) = 1.0
    ENDDO
  ENDDO

  DO I=1,M
    DO J=1,N
      SUM = 0.0
      DO K=1,N
        SUM = SUM + A(I,K) * B(K,J)
      ENDDO
      C(I,J) = SUM
    ENDDO
  ENDDO

!print *,c

END PROGRAM
