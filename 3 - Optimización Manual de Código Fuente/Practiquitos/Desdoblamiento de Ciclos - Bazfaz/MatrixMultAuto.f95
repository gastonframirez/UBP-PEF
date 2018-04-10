!
! Autor: Maximiliano A. Eschoyez
!
! Wed Aug 22 12:05:19 ART 2007
!

PROGRAM MATRIXMULT

  IMPLICIT NONE

  INTEGER :: N,M
  PARAMETER (N=1000, M=1000)
!  PARAMETER (N=10, M=10)
  REAL :: A(M,N), B(M,N), C(M,N)

  A = 2.0
  B = 1.0

!  C = A * B
  C = MATMUL(A,B)

!PRINT *,C

END PROGRAM
