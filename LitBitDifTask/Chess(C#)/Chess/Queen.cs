using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Chess
{
    class Queen : Piece
    {
        MyColor QueenColor;
        public Queen(MyColor C, string n) : base(C, n)
        {
            col = C;
            QueenColor = C;
            PictureName = n;
            IsKing = false;
        }

        public override bool IsLegal(int sr, int sc, int er, int ec, Piece[,] Ps)
        {
            if ((DiagonallyClear(sr, sc, er, ec, Ps) == true) && (IsDiagonal(sr, sc, er, ec) == true) 
                && (Ps[er, ec] == null || Ps[er, ec].col != QueenColor))
                return true;
            else if (VerticallyClear(sr, sc, er, ec, Ps) == true && (IsVertical(sr, sc, er, ec) == true) 
                && (Ps[er, ec] == null || Ps[er, ec].col != QueenColor))
                return true;
            else if (HorizontallyClear(sr, sc, er, ec, Ps) == true && (IsHorizontal(sr, sc, er, ec) == true)
                && (Ps[er, ec] == null || Ps[er, ec].col != QueenColor))
                return true;
            else
                return false;
        }
    }
}
