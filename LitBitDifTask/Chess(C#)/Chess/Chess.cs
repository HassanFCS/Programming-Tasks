using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Chess
{
    public partial class Chess : Form
    {
        const int Dim = 8;
        int sr, sc, er, ec;
        Piece[ , ] Ps = new Piece[Dim, Dim];
        Cell[ , ] Cs = new Cell[Dim, Dim];
        bool SelectSource = true;
        MyColor Player = MyColor.White;
        Cell Source;
        Cell Destination;


        public Chess()
        {
            InitializeComponent();
        }

        void Init()
        {
            ChessPanel.Controls.Clear();
            TurnMessage.Text = "Whites Turn";
            for (int r=0; r<Dim; r++)
            {
                for (int c=0; c<Dim; c++)
                {
                    if (r == 1)
                        Ps[r, c] = new Pawn(MyColor.Black, "Black_Pawn.png");
                    else if (r == 0 && (c==0 || c==7))
                        Ps[r, c] = new Rook(MyColor.Black, "Black_Rook.png");
                    else if (r == 0 && (c == 1 || c == 6))
                        Ps[r, c] = new Knight(MyColor.Black, "Black_Knight.png");
                    else if (r == 0 && (c == 2 || c == 5))
                        Ps[r, c] = new Bishop(MyColor.Black, "Black_Bishop.png");
                    else if (r == 0 && c == 3)
                        Ps[r, c] = new Queen(MyColor.Black, "Black_Queen.png");
                    else if (r == 0 && c == 4)
                        Ps[r, c] = new King(MyColor.Black, "Black_King.png");
                    else if (r == 6)
                        Ps[r, c] = new Pawn(MyColor.White, "White_Pawn.png");
                    else if (r == 7 && (c == 0 || c==7))
                        Ps[r, c] = new Rook(MyColor.White, "White_Rook.png");
                    else if (r == 7 && (c == 1 || c == 6))
                        Ps[r, c] = new Knight(MyColor.White, "White_Knight.png");
                    else if (r == 7 && (c == 2 || c == 5))
                        Ps[r, c] = new Bishop(MyColor.White, "White_Bishop.png");
                    else if (r == 7 && c == 3)
                        Ps[r, c] = new Queen(MyColor.White, "White_Queen.png");
                    else if (r == 7 && c == 4)
                        Ps[r, c] = new King(MyColor.White, "White_King.png");
                    else
                        Ps[r, c] = null;
                    //--------------------------------//

                    MyColor cc = (((r + c) % 2 == 0) ? MyColor.White : MyColor.Black);
                    Cs[r, c] = new Cell(r, c, cc, Ps[r, c], ChessPanel.Width, ChessPanel.Height, Dim);
                    Cs[r, c].Click += new System.EventHandler(CellSelected);
                    ChessPanel.Controls.Add(Cs[r, c]);
                }
            }
        }

        private bool IsCheck()
        {
            int Kr=0, Kc=0;
            if (Player == MyColor.White)
            {
                for (int R = 0; R < Dim; R++)
                {
                    for (int C = 0; C < Dim; C++)
                    {
                        if (((Ps[R, C].col != Player) || Ps[R, C] != null) && Ps[R, C].IsKing == true)
                        {
                            Kr = R; Kc = C; R = 8;
                            break;
                        }
                    }
                }
            }
            else if (Player == MyColor.Black)
            {
                for (int R = Dim-1; R >=0; R--)
                {
                    for (int C = Dim-1; C >= 0; C--)
                    {
                        if (((Ps[R, C].col != Player) || Ps[R, C] != null) && Ps[R, C].IsKing == true)
                        {
                            Kr = R; Kc = C; R = 0;
                            break;
                        }
                    }
                }
            }
            for (int R = 0; R < Dim; R++)
            {
                for (int C = 0; C < Dim; C++)
                {
                    if (Ps[R, C] != null)
                    {
                        if (Ps[R, C].IsLegal(R, C, Kr, Kc, Ps) == true)
                        {
                            Cs[Kr, Kc].BackColor = Color.Red;
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        private bool SelfCheck()
        {
            int Kr = 0, Kc = 0;
            if (Player == MyColor.Black)
            {
                for (int R = 0; R < Dim; R++)
                {
                    for (int C = 0; C < Dim; C++)
                    {
                        if ((Ps[R, C] == null || (Ps[R, C].col == Player) ) && Ps[R, C].IsKing == true)
                        {
                            Kr = R; Kc = C; R = 8;
                            break;
                        }
                    }
                }
            }
            else if (Player == MyColor.White)
            {
                for (int R = Dim - 1; R >= 0; R--)
                {
                    for (int C = Dim - 1; C >= 0; C--)
                    {
                        if ((Ps[R, C] == null || (Ps[R, C].col == Player) ) && Ps[R, C].IsKing == true)
                        {
                            Kr = R; Kc = C; R = 0;
                            break;
                        }
                    }
                }
            }
            for (int R = 0; R < Dim; R++)
            {
                for (int C = 0; C < Dim; C++)
                {
                    if (Ps[R, C] != null)
                    {
                        if (Ps[R, C].IsLegal(R, C, Kr, Kc, Ps) == true)
                        {
                            Cs[Kr, Kc].BackColor = Color.Red;
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        private bool PossibleKingMove(Piece[,] Ps, Cell[,] Cs, int sr, int sc, int er, int ec)
        {
            Piece[,] CopyPs = new Piece[Dim, Dim];
            Cell[,] CopyCs = new Cell[Dim, Dim];
            for (int R=0; R<Dim; R++)
            {
                for (int C=0; C<Dim; C++)
                {
                    CopyPs[R, C] = Ps[R, C];
                    CopyCs[R, C] = Cs[R, C];
                }
            }
            if (IsValidPieceDestination(sr, sc, er, ec, Ps))
            {
                Piece SP = Source.aP;
                //Source.aP = null;

                //Destination.aP = SP;
                int SR = Source.ri, SC = Source.ci;
                int ER = Destination.ri, EC = Destination.ci;

                CopyPs[ER, EC] = CopyPs[SR, SC];
                CopyPs[SR, SC] = null;
                if (SelfCheck() == true)
                    return false;
                else
                    return true;
            }
            return false;
        }

        private void Highlight(Cell[,] Cs, int sr, int sc, int Dim)
        {
            for (int R = 0; R < Dim; R++)
            {
                for (int C = 0; C < Dim; C++)
                {
                    if (Source.aP.IsLegal(sr, sc, R, C, Ps) == true)
                    {
                        Cs[R, C].BackColor = Color.LightGreen;
                        if (Cs[R, C].aP != null)
                        {
                            if (Cs[R, C].aP.col != Cs[sr, sc].aP.col)
                                Cs[R, C].BackColor = Color.Red;
                        }
                    }
                }
            }
        }

        private void UnHighlight(Cell[,] Cs, int Dim)
        {
            for (int R = 0; R < Dim; R++)
            {
                for (int C = 0; C < Dim; C++)
                {
                    Cs[R, C].BackColor = (((R + C) % 2 == 0) ? Color.White : Color.Gray);
                }
            }
        }

        public void SourceSelection(object sender, EventArgs e)
        {
            Source = (Cell)sender;
        }

        public void DestinationSelection(object sender, EventArgs e)
        {
            Destination = (Cell)sender;
        }

        private void CellSelected(object sender, EventArgs e)
        {
            if (SelectSource)
            {
                SourceSelection(sender, e);
                sr = Source.ri;
                sc = Source.ci;
                if (IsValidPieceSelection(sr, sc, er, ec, Ps))
                {
                    SelectSource = false;
                    Highlight(Cs, sr, sc, Dim);
                }
                else
                {
                    MessageBox.Show("Other Players turn");
                    UnHighlight(Cs, Dim);
                }
            }
            else
            {
                DestinationSelection(sender, e);
                er = Destination.ri;
                ec = Destination.ci;
                if (IsValidPieceDestination(sr, sc, er, ec, Ps))
                {
                    //if (SelfCheck(Ps, Cs) == false && PossibleKingMove(Ps, Cs, sr, sc, er, ec) == false)
                    //{
                    //    MovePiece();
                    //    UnHighlight(Cs, Dim);
                    //    TurnChange();
                    //}
                    if (PossibleKingMove(Ps, Cs, sr, sc, er, ec) == true)
                    {
                        MovePiece();
                        UnHighlight(Cs, Dim);
                        TurnChange();
                    }
                    //else
                    //{
                    //    SelfCheck(Ps, Cs);
                    //    MessageBox.Show("Can't Move, CHECK!");
                    //    UnHighlight(Cs, Dim);
                    //    return;
                    //}
                }
                else 
                {
                    UnHighlight(Cs, Dim);
                    if (sr != er && sc != ec)
                        MessageBox.Show("Wrong Destination Selected");
                }
                SelectSource = true;
            }
        }

        void MovePiece()
        {
            Piece SP = Source.aP;
            Source.aP = null;

            Destination.aP = SP;
            int sr = Source.ri, sc = Source.ci;
            int er = Destination.ri, ec = Destination.ci;

            Ps[er, ec] = Ps[sr, sc];
            Ps[sr, sc] = null;

            UnHighlight(Cs, Dim);

            Destination.aP.Draw(Destination);
            Source.Image = null;
            //if(IsCheck(Ps, Cs)==true)
            //    MessageBox.Show("Check!");
        }


        private bool IsValidPieceSelection(int sr, int sc, int er, int ec, Piece[ , ] Ps)
        {
            if (Source.aP == null)
                return false;
            else
                return (Source.aP.col== Player);
        }

        private bool IsValidPieceDestination(int sr, int sc, int er, int ec, Piece[ , ] Ps)
        {
            return ( (Destination.aP == null || Destination.aP.col != Player) && Source.aP.IsLegal(sr, sc, er, ec, Ps));
        }

        void TurnChange()
        {
            if (Player == MyColor.White)
            {
                Player = MyColor.Black;
                TurnMessage.Text = "Blacks Turn";
            }
            else
            {
                Player = MyColor.White;
                TurnMessage.Text = "Whites Turn";
            }
        }

        private void Start_Click(object sender, EventArgs e)
        {
            Init();
        }

        private void TurnMessage_TextChanged(object sender, EventArgs e)
        {

        }

    }
}
