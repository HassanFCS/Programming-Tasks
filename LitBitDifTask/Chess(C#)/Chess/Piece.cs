using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Data;
using System.Windows.Forms;

namespace Chess
{
    enum MyColor {White, Black};
    abstract class Piece
    {
        public MyColor col;
        public string PictureName;
        public bool IsKing = false;

        public Piece(MyColor C, string n)
        {
            col = C;
            PictureName = n;
        }

        public abstract bool IsLegal(int sr, int sc, int er, int ec, Piece[ , ] Ps);

        public void Draw(Cell C)
        {
            C.Image = Image.FromFile("..\\..\\Resources\\" + PictureName);
        }


        public static bool IsVertical(int sr, int sc, int er, int ec)
        {
            return sc == ec;
        }
        public static bool IsHorizontal(int sr, int sc, int er, int ec)
        {
            return sr == er;
        }
        public static bool IsDiagonal(int sr, int sc, int er, int ec)
        {
            return Math.Abs(sr-er) == Math.Abs(sc-ec);
        }
        public static bool HorizontallyClear(int sri, int sci, int dri, int dci, Piece[,] Ps)
        {
            int StartC = (sci < dci) ? sci + 1 : dci + 1;
            int EndC = (sci > dci) ? sci-1 : dci-1;
            for (int c = StartC; c <= EndC; c++)
            {
                if (Ps[sri, c] != null)
                    return false;
            }
            return true;
        }
        public static bool VerticallyClear(int sri, int sci, int dri, int dci, Piece[,] Ps)
        {
            int StartR = (sri < dri) ? (sri + 1) : (dri + 1);
            int EndR = (sri > dri) ? (sri-1) : (dri-1);
            for (int r = StartR; r <= EndR; r++)
            {
                if (Ps[r, sci] != null)
                    return false;
            }
            return true;
        }
        public static bool DiagonallyClear(int sr, int sc, int er, int ec, Piece[,] ps)
        {
            //int dr = (sri < dri) ? dri - sri : sri - dri;
            //int dc = (sci < dci) ? dci - sci : sci - dci;
            //int StartR = (sri < dri) ? sri+1: dri+1;
            //int EndR = (sri > dri) ? sri-1: dri-1;
            //if (dr == dc && StartR > 0)
            //{
            //    for (int i = StartR; i <= EndR; i++)
            //    {
            //        if (Ps[i, i] != null)
            //            return false;
            //    }
            //}
            //if (dr == dc && StartR < 0)
            //{
            //    for (int i = EndR; i >= EndR; i--)
            //    {
            //        if (Ps[i, i] != null)
            //            return false;
            //    }
            //}
            //return true;


            if (sr < er && sc < ec)
            {
                for (int i = sr + 1, j = sc + 1; (i < er) && (j < ec); i++, j++)
                {
                    if (ps[i, j] != null)
                        return false;
                }
                return true;
            }
            else if (sr > er && sc > ec)
            {
                for (int i = sr - 1, j = sc - 1; (i > er) && (j > ec); i--, j--)
                {
                    if (ps[i, j] != null)
                        return false;
                }
                return true;
            }
            else if (sr < er && sc > ec)
            {
                for (int i = sr + 1, j = sc - 1; (i < er) && (j > ec); i++, j--)
                {
                    if (ps[i, j] != null)
                    {
                        return false;
                    }
                }
                return true;
            }
            else if (sr > er && sc < ec)
            {
                for (int i = sr - 1, j = sc + 1; (i > er) && (j < ec); i--, j++)
                {
                    if (ps[i, j] != null)
                    {
                        return false;
                    }
                }
                return true;
            }
            else
                return false;
        }
        public static bool DiagonallyClearPawn(int sr, int sc, int er, int ec, Piece[,] ps)
        {
            if (sr < er && sc < ec)
            {
                for (int i = sr + 1, j = sc + 1; (i <= er) && (j <= ec); i++, j++)
                {
                    if (ps[i, j] != null)
                        return false;
                }
                return true;
            }
            else if (sr > er && sc > ec)
            {
                for (int i = sr - 1, j = sc - 1; (i >= er) && (j >= ec); i--, j--)
                {
                    if (ps[i, j] != null)
                        return false;
                }
                return true;
            }
            //else
            //    return false;
            else if (sr < er && sc > ec)
            {
                for (int i = sr + 1, j = sc - 1; (i <= er) && (j >= ec); i++, j--)
                {
                    if (ps[i, j] != null)
                    {
                        return false;
                    }
                }
                return true;
            }
            else if (sr > er && sc < ec)
            {
                for (int i = sr - 1, j = sc + 1; (i >= er) && (j <= ec); i--, j++)
                {
                    if (ps[i, j] != null)
                    {
                        return false;
                    }
                }
                return true;
            }
            else
                return false;
        }

    }
}

