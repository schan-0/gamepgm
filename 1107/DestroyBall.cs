using UnityEngine;

public class DestroyBall : MonoBehaviour
{
    void Start()
    {
        Destroy(gameObject, 5.0f);
    }
}
