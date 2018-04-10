!
! Autor: Maximiliano A. Eschoyez
!
! Wed Aug 22 12:05:19 ART 2007
!

PROGRAM MATRIXMULT

  IMPLICIT NONE

  INTEGER :: I,J,N,M
!  PARAMETER (N=10, M=10)
  PARAMETER (N=1000, M=1000)
  REAL :: A(M,N), B(M,N), C(M,N)

  DO I=1,M
    DO J=1,N
      A(I,J) = 2.0
      B(I,J) = 1.0
    ENDDO
  ENDDO

  DO I=1,M
    DO J=1,N
      C(I,J) = SUM ( A(I,:) * B(:,J) )
    ENDDO
  ENDDO

!print *,c

END PROGRAM
