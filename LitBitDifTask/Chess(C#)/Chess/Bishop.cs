using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Chess
{
    class Bishop : Piece
    {
        MyColor BishopColor;
        public Bishop(MyColor C, string n) : base(C, n)
        {
            col = C;
            BishopColor = C;
            PictureName = n;
            IsKing = false;
        }

        public override bool IsLegal(int sr, int sc, int er, int ec, Piece[,] Ps)
        {
            if (DiagonallyClear(sr, sc, er, ec, Ps) == true && (Math.Abs(sc - ec) == Math.Abs(sr - er)) 
                && ((Ps[er, ec] == null || Ps[er, ec].col != BishopColor)))
                return true;
            else
                return false;
        }
    }
}
