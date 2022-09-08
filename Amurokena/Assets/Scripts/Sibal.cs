using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Sibal : MonoBehaviour
{
    public GameObject pixel;
    bool[,] map = new bool[10,25];
    int x, y;

    void Start()
    {
        
    }

    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            x = Random.Range(0, 10);
            y = Random.Range(0, 25);
            pixel.transform.position = new Vector2(x * 0.4f, y * 0.4f);
            map[x,y] = true;
            Instantiate(pixel);
        }
    }
}
