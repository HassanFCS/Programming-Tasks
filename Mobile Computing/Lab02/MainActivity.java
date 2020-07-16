package com.example.lab02;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
//Activity 1
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Intent il=getIntent();
        if(il!=null){
            String Str = il.getStringExtra("msg1");
            TextView TV=findViewById(R.id.R1Window);
            TV.setText(Str);
        }
    }

    public void onclick_send(View view){
        EditText TB=findViewById(R.id.S1Window);
        String Str=TB.getText().toString();
        Intent i=new Intent(this, MainActivity2.class);
        i.putExtra("msg1",Str);
        startActivity(i);
    }
}
