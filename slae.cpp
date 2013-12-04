#include "SLAE.h"

slae::slae( diagMatr & iA, myVector & iAprX, myVector & iRez ):
    m_A( iA ),
    m_AprX( iAprX ),
    m_Rez( iRez )
{

}

void slae::iteration()
{
    int i, j, index;
    double sum;
    for( i = 0; i < m_A.getSize(); ++i )
    {
        sum = 0;
        for( j = 0; j < 7; ++j )
        {
            index = i + m_A.getIndex( j );
            if( index > -1 && index < 14 )
                sum += m_A[ i ][ j ] * m_AprX[ index ];
        }
        m_AprX[ i ] = m_AprX[ i ] + ( m_Rez[ i ] - sum ) / m_A[ i ][ 3 ];
    }
}

void slae::gaussSeidel( myVector & oX, int iMaxIter, int oIterCount )
{
    int k;
    for( k = 0; k < iMaxIter; ++k)
        iteration();
    oX = m_AprX;
}
