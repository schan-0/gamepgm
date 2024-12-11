using UnityEngine;

public class DeathZone : MonoBehaviour
{
    public static bool dead;

    void Start()
    {
        dead = false;
    }

    private void OnTriggerEnter(Collider col)
    {
        if(col.gameObject.tag == "Hiyoko")
        {
            UIController.gameOver = true;
            dead = true;
        }
    }
}
